#include <iostream>
using namespace std;

// program to illustrate the use of this pointer
// int main()
// {
//     string food = 'hello';
//     string* fooptr = &food;

//     cout << "Address of ptr" << foodptr << endl;
//     cout << "Value of ptr" << *foodptr << endl;
// }

// program to show pointer arithmetic operation

int main()
{
    int num[] = {23, 45, 64, 23, 64};
    int *ptr = num;
    cout << *ptr << endl;
    ptr++;
    cout << *ptr << endl;
    ptr += 2;
    cout << *ptr << endl;
    ptr -= 1;
    cout << *ptr << endl;
}