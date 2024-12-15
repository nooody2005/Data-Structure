
#include "Stack.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Is_balance(const char *expression)
{
    Stack2 s;
    CreateStack2(expression, &s);

    for (int i = 0; expression[i]; i++)
    {
        char current = expression[i];

        if (current == '(' || current == '[' || current == '{')
        {
            push2(&s, current);
        }
        else if (current == ')' || current == ']' || current == '}')
        {
            if (s.top == 0)
            {
                return 0; // Unbalanced
            }

            char top = pop2(&s);

            if ((current == ')' && top != '(') ||
                (current == ']' && top != '[') ||
                (current == '}' && top != '{'))
            {
                return 0; // Mismatch
            }
        }
    }

    return s.top == 0; // Balanced if stack is empty
}
//======================== Infix to postfix convertion ===================
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    else
        return 0;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;

    else if (x == '*' || x == '/')
        return 2;

    return 0;
}

// char *Convert(char *infix)
// {
//     Stack2 s;
//     CreateStack2(infix, &s);

//     char *postfix = (char *)malloc(strlen(infix) + 1);
//     int i = 0, j = 0;

//     while (infix[i] != '\0')
//     {
//         if (!isOperand(infix[i]))
//         { // Operand
//             postfix[j++] = infix[i++];
//         }
//         else
//         { // Operator
//             while (s.top > 0 && pre(Stack_Top2(&s)) >= pre(infix[i]))
//             {
//                 postfix[j++] = pop2(&s);
//             }
//             push2(&s, infix[i++]);
//         }
//     }

//     while (s.top > 0)
//     {
//         postfix[j++] = pop2(&s);
//     }

//     postfix[j] = '\0';
//     return postfix;
// }
char *Convert(char *infix)
{
    Stack2 s;
    CreateStack2(infix, &s);

    char *postfix = (char *)malloc(strlen(infix) * 2 + 1); // Allocate extra space
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperand(infix[i]) && !isspace(infix[i])) // number and check if not space(number is not more 1 digit or not)
        {                                               // If it's a number
            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add a space to separate numbers
        }
        else if (isOperand(infix[i]))
        { // If it's an operator
            while (s.top > 0 && pre(Stack_Top2(&s)) >= pre(infix[i]))
            {
                postfix[j++] = pop2(&s);
                postfix[j++] = ' ';
            }
            push2(&s, infix[i++]);
        }
        else
        {
            i++; // Skip spaces or other characters
        }
    }

    while (s.top > 0)
    { // Empty the stack
        postfix[j++] = pop2(&s);
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0'; // Remove the last space
    return postfix;
}

// int Eval(char *postfix)
// {
//     Stack s;
//     CreateStack(&s);    // Create from create fun..  of type1  ..need it int
//     int i, x, y, r;

//     for (i = 0; postfix[i] != '\0'; i++)
//     {
//         if (!isOperand(postfix[i]))
//         {                               // not Operand
//             push(postfix[i] - '0', &s); // Convert char to int
//         }
//         else
//         { // Operator
//             x = pop(&s);
//             y = pop(&s);
//             switch (postfix[i])
//             {
//             case '+':
//                 r = y + x;
//                 break;
//             case '-':
//                 r = y - x;
//                 break;
//             case '*':
//                 r = y * x;
//                 break;
//             case '/':
//                 r = y / x;
//                 break;
//             }
//             push(r, &s);
//         }
//     }

//     return pop(&s);
// }
// ==============Evalution of postfix =======================
int Eval(char *postfix)
{
    Stack s;
    CreateStack(&s);

    int i = 0, x, y, r;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        { // If it's a number
            int num = 0;
            sscanf(&postfix[i], "%d", &num); // Extract the number
            push(num, &s);

            // Skip the digits in the string
            while (isdigit(postfix[i]))
                i++;
        }
        else if (postfix[i] == ' ')
        {
            i++; // Skip spaces
        }
        else if (isOperand(postfix[i]))
        { // operator
            x = pop(&s);
            y = pop(&s);
            switch (postfix[i])
            {
            case '+':
                r = y + x;
                break;
            case '-':
                r = y - x;
                break;
            case '*':
                r = y * x;
                break;
            case '/':
                if (x == 0)
                {
                    printf("Invalid operator.."); // Invalid argument pole=zero
                    return 0;
                }
                r = y / x;
                break;
            }
            push(r, &s);
            i++;
        }
    }

    return pop(&s);
}

int main()
{
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (Is_balance(expression))
    {
        printf("The parentheses are balanced.\n");
        char *postfix = Convert(expression);
        int res = Eval(postfix);
        printf("Result = %d\n", res);
        free(postfix);
    }
    else
    {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
