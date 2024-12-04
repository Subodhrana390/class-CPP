#include <iostream>
using namespace std;

/* ************************** Program 13 ********************* */
/*
class Nested
{
public:
    int num;

    void getNum()
    {
        int n;
        cout << "Enter a integer ";
        cin >> n;
        num = n;
    }

    void show()
    {
        getNum();
        cout << "Input is " << num << endl;
    }
};

int main()
{
    cout << "SUBODH RANA \nURN: 2302689\n";
    Nested M1;
    M1.show();
}
*/
/* ************************** Program 14 ********************* */
/*

class Test
{
public:
    static int count;

    Test()
    {
        count++;
    }

    static void showCount()
    {
        cout << "No of objects created: " << count << endl;
    }
};

int Test::count = 0;

int main()
{
    cout << "SUBODH RANA \nURN: 2302689" << endl;

    Test obj1;
    Test obj2;

    Test::showCount();

    return 0;
}
*/
/* ************************** Program 15 ********************* */

class ConstrutorConcept
{
    int x;
    int y;

public:
    ConstrutorConcept()
    {
        cout << "default Constructor" << endl;
    }

    ConstrutorConcept(int a, int b)
    {
        cout << "Parameterised Constructor" << endl;
        x = a;
        y = b;
    }

    ConstrutorConcept(ConstrutorConcept &c1)
    {
        cout << "Copy Constructor" << endl;
        x = c1.x;
        y = c1.y;
    }

    void getVal(int a, int b = 0)
    {
        x = a;
        y = b;
    }

        void show()
    {
        cout << "x = " << x << endl;
        if (y)
        {
            cout << "y = " << y << endl;
        }
    }
};

int main()
{
    cout << "SUBODH RANA \nURN: 2302689\n";
    ConstrutorConcept c1;
    c1.getVal(2, 4);
    c1.show();
    ConstrutorConcept c2(3, 7);
    c2.show();
    ConstrutorConcept c3(c2);
    c3.show();
}
