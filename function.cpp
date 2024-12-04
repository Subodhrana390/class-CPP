#include <iostream>
using namespace std;

class Base
{
protected:
    int num;

public:
    Base(int n) { num = n; }

    virtual void Convert()
    {
        int binaryNum[32];
        int i = 0;
        int n = this->num;
        while (n > 0)
        {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
            cout << binaryNum[j];
        cout << endl;
    }
};

class Derived : public Base
{
public:
    Derived(int n) : Base(n) {}

    void Convert()
    {
        int octalNum[100];
        int i = 0;
        int n = this->num;
        while (n != 0)
        {
            octalNum[i] = n % 8;
            n = n / 8;
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
            cout << octalNum[j];
        cout << endl;
    }
};

int main()
{
    Base *basePtr;

    Base baseObj(90);
    Derived derivedObj(765);

    basePtr = &baseObj;
    cout << "Binary representation of 90: ";
    basePtr->Convert();

    basePtr = &derivedObj;
    cout << "Octal representation of 765: ";
    basePtr->Convert();

    return 0;
}
