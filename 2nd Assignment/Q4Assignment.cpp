#include <iostream>
#include <stdexcept>
using namespace std;

void readNumbers(double &num1, double &num2)
{
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    if (cin.fail())
    {
        throw invalid_argument("Invalid input! Please enter numeric values.");
    }
}

double divide(double num1, double num2)
{
    if (num2 == 0)
    {
        throw runtime_error("Division by zero error.");
    }
    return num1 / num2;
}

int main()
{
    double a, b, result;
    try
    {
        readNumbers(a, b);
        result = divide(a, b);
        cout << "Result: " << result << endl;
    }
    catch (invalid_argument &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    catch (runtime_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
