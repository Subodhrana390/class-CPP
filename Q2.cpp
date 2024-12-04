#include <iostream>
using namespace std;

class A;

class B
{
    int ft;
    int inch;

public:
    B(int a = 0, int b = 0)
    {
        ft = a;
        inch = b;
    }

    void display()
    {
        cout << "ft: " << ft << " & inch: " << inch << endl;
    }

    friend A addDistance(A &a, B &b);
};

class A
{
    int m, cm;

public:
    A(int x = 0, int y = 0)
    {
        m = x;
        cm = y;
    }

    void display()
    {
        cout << "m: " << m << " & cm: " << cm << endl;
    }

    friend A addDistance(A &a, B &b);
};

A addDistance(A &a, B &b)
{
    A result;
    int centi = b.ft * 30.48 + b.inch * 2.54;
    result.cm = a.cm + centi;
    result.m = a.m + (result.cm / 100);
    result.cm = result.cm % 100;
    return result;
}

int main()
{
    A obj1(2, 3);
    B obj2(1, 6);

    cout << "Object 1 (A) - Distance in meters and centimeters: ";
    obj1.display();
    cout << "Object 2 (B) - Distance in feet and inches: ";
    obj2.display();

    A result = addDistance(obj1, obj2);

    cout << "Result after adding distances: ";
    result.display();

    return 0;
}
