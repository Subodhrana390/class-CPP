#include <iostream>
using namespace std;

void updateVar(int *a)
{
    *a += 10;
}

int main()
{
    int x = 5;
    cout << "Before update: " << x << endl;

    updateVar(&x);

    cout << "After update: " << x << endl;
    return 0;
}
