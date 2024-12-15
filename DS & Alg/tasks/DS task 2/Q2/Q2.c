/*2- write a program to convert an infix Expression to its Equivalent Postfix using
Stack*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct 
{
    char data[MAX];
    int top;
} Stack;

void CreateStack(Stack* s) 
{
    s->top = -1;
}

int isFull(Stack* s) 
{
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) 
{
    return s->top == -1;
}

void push(Stack* s, char value) 
{
    if (isFull(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

char pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

char peek(Stack* s) 
{
    if (isEmpty(s)) 
    {
        return -1;
    }
    return s->data[s->top];
}

// Function to return precedence of operators
int precedence(char op) 
{
    // switch(op) {
    //     case '+':
    //     case '-': return 1;
    //     case '*':
    //     case '/': return 2;
    //     case '^': return 3;
    // }

    if (op == '+' || op == '-')     return 1;
    else if (op == '*'|| op == '/') return 2;
    else if (op == '^')             return 3;
    else                            return 0;

}

// Function to check if the character is an operator
int isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) 
{
    Stack s;
    CreateStack(&s);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        char token = infix[i];

        // If the token is an operand, add it to the postfix expression
        if (isalnum(token)) 
        {
            postfix[j++] = token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') 
        {
            push(&s, token);
        }
        // If the token is ')', pop from the stack until '(' is found
        else if (token == ')') 
        {
            while (!isEmpty(&s) && peek(&s) != '(') 
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '('
        }
        // If the token is an operator
        else if (isOperator(token)) 
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) 
            {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&s)) 
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null --> postfix expression
}

int main() 
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Equivalent Postfix expression: %s\n", postfix);

    return 0;
}
