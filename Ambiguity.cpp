#include <iostream>
#include <cstring>
using namespace std;
/*
class Base
{
public:
    void display()
    {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "Derived class display function" << endl;
    }
};

int main()
{
    Derived obj;
    obj.display();
    obj.Base::display();

    return 0;
}
*/

// Ambiguity in double inheritance
/*
class Base1
{
public:
    void display()
    {
        char arr[] = "Engineering Discipline.";
        cout << "Original String:\n"
             << arr << endl;
        cout << "String in lowercase:\n";
        for (int x = 0; x < strlen(arr); x++)
            putchar(tolower(arr[x]));
    }
};

class Base2
{
public:
    void display()
    {
        char arr[] = "Engineering Discipline.";
        cout << "\nOriginal String:\n"
             << arr << endl;
        cout << "String in lowercase:\n";
        for (int x = 0; x < strlen(arr); x++)
            putchar(toupper(arr[x]));
    }
};

class Derived : public Base1, public Base2
{

public:
    void display()
    {
        cout << "Derived Class of Base 1 and Base 2" << endl;
    }
};

int main()
{
    Derived obj;
    obj.display();
    obj.Base1::display();
    obj.Base2::display();
    return 0;
}
*/
// illustrate the concept of virtual base class/multipath inheritance

class Class
{
protected:
    string ClassName;
    string sectionCode;

public:
    void getClassName()
    {
        cout << "Enter Class Name :";
        getline(cin, ClassName);
    }
};

class Section1 : public virtual Class
{
public:
    void getSectionCode1()
    {
        cout << "Enter section Code :";
        getline(cin, sectionCode); j
    }
    void showSectionCode2()
    {
        cout << "Section Code of Section 1 :" << sectionCode << endl;
    }
};

class Section2 : public virtual Class
{
public:
    void getSectionCode2()
    {
        cout << "Enter section Code :";
        getline(cin, sectionCode);
    }
    void showSectionCode2()
    {
        cout << "Section Code of Section 2 :" << sectionCode << endl;
    }
};

class combinedClass : public Section1,
                      public Section2
{
public:
    void display()
    {
        cout << "combined Class" << endl;
    }

};

int main()
{
    combinedClass C;
    C.display();
    C.getSectionCode1();
    C.showSectionCode1();
    C.getSectionCode2();
    C.showSectionCode2();
}