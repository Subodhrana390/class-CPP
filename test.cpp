// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class MyClass
{

public:
    static int count;
    int id;
    MyClass()
    {
        id = count;
        count++;
    }

    void display()
    {
        cout << "Object with id " << id << " created." << endl;
    }
};

int MyClass::count = 1;

int main()
{
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;
    obj1.display();
    obj2.display();
    obj3.display();
    return 0;
}