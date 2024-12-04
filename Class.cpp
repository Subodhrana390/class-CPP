#include <iostream>
using namespace std;

class empty
{
};

class cDate
{
    int mDay, mMonth, mYear;

public:
    cDate()
    {
        mDay = 10;
        mMonth = 11;
        mYear = 1999;
    }
    cDate(int d, int m, int y)
    {
        mDay = d;
        mMonth = m;
        mYear = y;
    }
    void display()
    {
        cout << "day : " << mDay << endl;
        cout << "Month : " << mMonth << endl;
        cout << "Year : " << mYear << endl;
    }
};

class cEmployee
{
protected:
    int Id;
    int BasicSal;
    cDate Bdate;

public:
    cEmployee()
    {
        Id = 1;
        BasicSal = 10000;
        Bdate = cDate();
    }
    cEmployee(int, int, int, int, int);
    void display();
};

cEmployee ::cEmployee(int i, int sal, int d, int m, int y)
{
    Id = i;
    BasicSal = sal;
    Bdate = cDate(d, m, y);
}
void cEmployee::display()
{
    cout << "Id : " << Id << endl;
    cout << "Salary :" << BasicSal << endl;
    Bdate.display();
}

class abstract_fun
{
public:
    virtual void display() = 0;
};

class Derived : public abstract_fun
{
public:
    void display()
    {
        cout << "This is a derived class inheritby abstract" << endl;
    }
};

int main()
{
    // Empty Class
    cout << "Subodh Rana URN:2302689" << endl;
    // empty E;
    // cout << "Empty Class:" << endl;
    // cout << "Size of Empty Class : " << sizeof E << endl;

    // Container Class
    // cout << "Container Class: " << endl;
    // cEmployee e1;
    // e1.display();
    // cout << "Second employee" << endl;
    // cEmployee e2(2, 20000, 11, 11, 1999);
    // e2.display();
    // // Abstract Class
    cout << "Abstract Class : " << endl;
    Derived D;
    D.display();
}