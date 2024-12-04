#include <iostream>
using namespace std;

// Program to overload unary minus operator
/*
class Space
{
    int x, y, z;

public:
    void getValue(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }

    void display()
    {
        cout << x << " " << y << " " << z << endl;
    }

    friend void operator-(Space &S);
};

void operator-(Space &S)
{
    S.x = -S.x;
    S.y = -S.y;
    S.z = -S.z;
}

int main()
{
    cout << "Vikram Yadav URN:2302708\n";
    Space S;
    S.getValue(10, -20, 30);
    S.display();
    -S;
    S.display();
    return 0;
}
/
*/
// program to overload prefix and postfix increment operator

class incrementOperator
{
    int count;

public:
    incrementOperator(int c = 0)
    {
        count = c;
    }

    incrementOperator &operator++()
    {
        ++count;
        return *this;
    }

    incrementOperator operator++(int)
    {
        incrementOperator temp = *this;
        count++;
        return temp;
    }

    void display()
    {
        cout << "Count: " << count << endl;
    }
};

int main()
{
    cout << "Vikram Yadav URN:2302708\n";
    incrementOperator c1(5);
    cout << "Original Count: ";
    c1.display();
    ++c1;
    cout << "Count After Prefix : ";
    c1.display();
    c1++;
    cout << "Count After Postfix : ";
    c1.display();

    return 0;
}

// program to overload binary operator overloading
/*
class Pair
{
    int a;
    int b;

public:
    Pair(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }
    friend Pair operator+(Pair &A, Pair &other);
    void display()
    {
        cout << "(" << a << ", " << b << ")" << endl;
    }
};

Pair operator+(Pair &A, Pair &other)
{
    return Pair(A.a + other.a, A.b + other.b);
}

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Pair p1(2, 3);
    Pair p2(4, 5);
    Pair p3 = p1 + p2;
    cout << "p1: ";
    p1.display();
    cout << "p2: ";
    p2.display();
    cout << "p1 + p2 = ";
    p3.display();
    return 0;
}
*/
// program to add two complex numbers using binary operator overloading
/*
    class Complex
{
    int a;
    int b;

public:
    Complex(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout << a << " + " << b << " i " << endl;
    }

    Complex operator+(Complex c1);
};

Complex Complex::operator+(Complex c1)
{
    Complex R;
    R.a = a + c1.a;
    R.b = b + c1.b;
    return R;
}

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Complex c1(5, 3), c2(3, 5);
    c1.display();
    c2.display();
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}*/