#include <iostream>
using namespace std;
int SIZE = 5;

// Program to find sum of element of 1D-Array
void SumofElement()
{
    int arr[SIZE] = {2, 4, 5, 6, 7};
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    cout << "\nSum of All Element = " << sum << endl;
};

// Program to  find the determinant of 3x3 matrix
void findDeterminant()
{
    int M[3][3] = {{1, 2, 3},
                   {2, 4, 5},
                   {4, 5, 7}};
    int determinant = (M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])) -
                      (M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])) +
                      (M[0][2] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    cout
        << "Determinant is" << determinant << endl;
}

// Program to swap two numbers using call by value & call by reference
void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After Swapping by Call by Value: "
         << "a = " << a << ", b = " << b << endl;
}

void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After Swapping by Call by Reference: "
         << "a = " << a << ", b = " << b << endl;
}

int main()
{
    cout << "Vikram Yadav URN:2302708\n";
    // SumofElement();
    findDeterminant();
    // int x = 5, y = 10;
    // swapByValue(x, y);
    // swapByReference(x, y);
    return 0;
}