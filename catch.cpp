#include <iostream>
#include <math.h>
using namespace std;

// Inside Block
/*
int main()
{
    int a, b;
    cout << "Enter two number a and b : ";
    cin >> a;

    try
    {
        if (a <= 0)
            throw "number is zero";
        cout << "Square root of " << a << " is " << sqrt(a) << endl;
    }
    catch (const char *errMsg)
    {
        cout << "Exception caught : " << errMsg << endl;
    }
}
*/

// Outside Block
/*
void SquareRoot(int a)
{
    if (a <= 0)
        throw a;
    else
        cout << "Square root of " << a << " is " << sqrt(a) << endl;
}

int main()
{
    int a;
    cout << "Enter value of a : ";
    cin >> a;

    try
    {
        SquareRoot(a);
    }
    catch (int e)
    {
        cout << "Exception caught : " << "a is number zero" << endl;
    }
}
*/

// Multiple Catches
void test(int a)
{
    if (a == 0)
        throw "Number is negative!";
    else if (a == 1)
        throw 1;
    else if (a == 2)
        throw 2.5;
    else
        cout << "Value of " << a << " is " << a << endl;
}

int main()
{
    int a;
    cout << "Enter value of a : ";
    cin >> a;

    try
    {
        test(a);
    }
    catch (const char *errmsg)
    {
        cout << "Caught occured :" << errmsg << endl;
    }
    catch (int e)
    {
        cout << "Exception caught : " << "integer Caught" << endl;
    }
    catch (double d)
    {
        cout << "Exception caught : " << "Decimal Value caught" << endl;
    }
    catch (...)
    {
        cout << "Exception occured!" << endl;
    }
}

// Rethrowing Exception

 divide(int a, int b)
{
    if(a==0) throw"Division By Zero!";
    cout<<"Su"
}