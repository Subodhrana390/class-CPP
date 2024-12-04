#include <bits/stdc++.h>
using namespace std;

class InSufficentError : public runtime_error
{
public:
    InSufficentError(const string &msg) : runtime_error(msg) {};
};

class InvalidAmount : public runtime_error
{
public:
    InvalidAmount(const string &msg) : runtime_error(msg) {}
};

// int main()
// {
//     int a, b;
//     cout << "Enter dividend & divisor :";
//     cin >> a >> b;

//     try
//     {
//         if (cin.fail())
//         {
//             throw invalid_argument("Invalid input! Please enter numeric values.");
//         }

//         if (b == 0)
//         {
//             throw InSufficentError("Divison by Zero ! not possible");
//         }

//         int result = a / b;
//         cout << "Result : " << result << endl;
//     }
//     catch (exception &e)
//     {
//         cout << e.what() << '\n';
//     }
// }

class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    void deposit(int amount)
    {
        if (amount < 0)
            throw InvalidAmount("Amount is greater than zero");

        balance += amount;
        cout << amount << "is credited successfully\n";
    }

    void withdraw(int amount)
    {

        if (amount < 0)
            throw InvalidAmount("Amount is greater than zero");
        // throw "Amount is greater than zero";
        if (amount >= balance)
            throw InvalidAmount("Amount should be lesser the balance");
        // throw "Amount should be lesser the balance";
        balance -= amount;
        cout << amount << "is debited successfully";
    }
};

int main()
{
    Customer C1("Rohit", 5000, 10);
    try
    {
        C1.deposit(100);
        C1.withdraw(6000);
    }
    catch (const InvalidAmount &e)
    {
        cout << e.what() << '\n';
    }
    catch (const char *e)
    {
        cout << e << '\n';
    }
    catch (...)
    {
        cout << "Exception occured " << endl;
    }
}