#include <iostream>
using namespace std;

class Arithmetic
{
protected:
    int a;
    int b;

public:
    Arithmetic(int m, int n)
    {
        a = m;
        b = n;
    }

    virtual void operation()
    {
        int result = a + b;
        cout << "Result of " << a << " & " << b << " is " << result << endl;
    }
};

class Substraction : public Arithmetic
{
public:
    Substraction(int y, int z) : Arithmetic(y, z) {}

    void operation()
    {
        int result = a - b;
        cout << "Result of " << a << " &" << b << " is " << result << endl;
    }
};

int main()
{
    Arithmetic *base;
    Arithmetic A1(2, 4);
    Substraction S(2, 4);
    base = &A1;
    A1.operation();
    base = &S;
    S.operation();
    return 0;
}

