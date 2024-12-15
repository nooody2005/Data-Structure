#include <iostream>

using namespace std;

class Triangular
{
private:
    int *A;
    int n;

public:
   
    Triangular(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];  
    }

   
    ~Triangular()
    {
        delete[] A;
    }

    
    void Set(int i, int j, int x)
    {
        if (i >= j)  
            A[i * (i - 1) / 2 + j - 1] = x;  
    }

    
    int Get(int i, int j)
    {
        if (i >= j)
            return A[i * (i - 1) / 2 + j - 1];  
        else
            return 0; 
    }


    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    cout << A[i * (i - 1) / 2 + j - 1] << "  ";  
                else
                    cout << "0  "; 
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, x;

    
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    Triangular tri(n);

    cout << "Enter the elements of the matrix:\n";
    for (int i = 1; i <= n; i++)  
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            tri.Set(i, j, x); 
        }
    }

    cout << "\nThe Lower Triangular Matrix is:\n";
    tri.display();

    return 0;
}
