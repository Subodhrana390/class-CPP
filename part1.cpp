#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Program 16
/*
class Test
{
    int *x;

public:
    Test(int a)
    {
        x = new int;
        *x = a;
        cout << "x = " << *x << endl;
    }
    ~Test()
    {
        delete x;
        cout<<"Desctructor";
    }
};

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Test t1(2);
    return 0;
}
*/
// Program 17
/*
class Test
{
    int *x;

public:
    Test(int a)
    {
        x = new int;
        *x = a;
        cout << "x = " << *x << endl;
    }
    ~Test()
    {
        cout << "destructor called";
        delete x;
    }
};

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Test t1(2);
    return 0;
}
*/

// program 18
/*
void func()
{
    class LocalClass
    {
        int x;

    public:
        LocalClass(int y)
        {
            x = y;
        }
        void display()
        {
            cout << "This is a value inside a local class = " << x << endl;
        }
    };
    int n;
    cout << "enter any value :- ";
    cin >> n;
    LocalClass obj(n);
    obj.display();
}

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    func();
    return 0;
}
*/
// program 19
/*
class Outer
{
    int outerData;

public:
    Outer(int data)
    {
        outerData = data;
    }

    class Inner
    {
        int innerData;

    public:
        Inner(int data)
        {
            innerData = data;
        }

        void display()
        {
            cout << "Inner class data: " << innerData << endl;
        }

        void accessOuter(Outer &outer)
        {
            cout << "Outer class data: " << outer.outerData << endl;
        }
    };
};
int main()
{
    cout << "SUBODH RANA URN:2302689\n";

    Outer outer(10);
    Outer::Inner inner(20);

    inner.display();
    inner.accessOuter(outer);

    return 0;
}
*/
// Program 20
/*
class Inline
{
    int x, y;

public:
    Inline(int a, int b)
    {
        x = a;
        y = b;
    }
    inline int max()
    {
        return (x > y) ? x : y;
    }

    inline int min()
    {
        return (x < y) ? x : y;
    }
};

int main()
{
    cout
        << "SUBODH RANA URN:2302689\n";
    int a = 10, b = 20;
    Inline obj(10, 20);
    cout << "Maximum of " << a << " and " << b << " is " << obj.max() << endl;
    cout << "Minimum of " << a << " and " << b << " is " << obj.min() << endl;

    return 0;
}
*/

// Program 21

class DefaultParams
{
public:
    void printMessage(string message, int count = 1, string prefix = "Default: ")
    {
        for (int i = 0; i < count; i++)
        {
            cout << prefix << message << endl;
        }
    }
};

int main()
{
    cout
        << "Vikram Yadav URN:2302708\n";
    DefaultParams obj;
    obj.printMessage("Hello, World!");
    obj.printMessage("Hello, Universe!", 3);
    obj.printMessage("Hello, !", 2, "Custom: ");

    return 0;
}

// Program 22
/*
class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    friend Complex addComplex(Complex &, Complex &);
    void displayComplex(Complex c)
    {
        cout << "Complex Number is  " << c.real << " + " << c.imag << " i " << endl;
    }
};

Complex addComplex(Complex &c1, Complex &c2)
{

    Complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}

int main()
{
    cout
        << "Vikram Yadav URN:2302708\n";
    Complex c1(10, 20);
    Complex c2(5, 10);
    Complex c3 = addComplex(c1, c2);
    c3.displayComplex(c3);
    return 0;
}
*/

// Program 23
/*
int main()
{
    cout
        << "SUBODH RANA URN:2302689\n";
    string str1 = "Hello, World!";
    string str2 = "hello, Mars!";
    string str3;

    cout << "Length of str1: " << strlen(str1) << endl;

    cout << "Character at index 5 in str1: " << str1.at(5) << endl;
    cout << "Character at index 5 in str1: " << str1[5] << endl;

    strcat(str1, " Happy");
    cout << "Substring from index 7 to 12: " << str1 << endl;

    bool isEqual = strcmp(str1, str2);
    if (isEqual)
    {
        cout << "The string is same";
    }
    else
    {
        cout << "The string is not same";
    }

    int index = str1.find("Hello");
    cout << "Hello" << " is a found at position" << index << endl;
    strcpy(str3, str1);
    cout
        << "str3 after append: " << str3 << endl;

    str3.insert(7, "Beautiful ");
    cout << "str3 after insert: " << str3 << endl;

    str3.erase(7, 9);
    cout << "str3 after erase: " << str3 << endl;

    str3.replace(7, 5, "Welcome ");
    cout << "str3 after replace: " << str3 << endl;

    str1.swap(str2);
    cout << "str1 after swap: " << str1 << endl;
    cout << "str2 after swap: " << str2 << endl;

    return 0;
}
*/