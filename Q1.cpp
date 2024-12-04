#include <iostream>
using namespace std;

class Charge
{
public:
    int totalCharge;
    int surcharge;
};

class generateBill
{
    string name;
    int Cunits;

public:
    generateBill(string name, int Cunits)
    {
        this->name = name;
        this->Cunits = Cunits;
    }

    Charge calculateAmount()
    {
        Charge c1;
        if (Cunits < 100)
        {
            c1.totalCharge = Cunits * 0.60;
        }
        else if (Cunits > 100 && Cunits < 300)
        {
            c1.totalCharge = 100 * 0.60 + (Cunits - 100) * 0.80;
        }
        else
        {
            c1.totalCharge = 100 * 0.60 + 200 * 0.80 + (Cunits - 300) * 0.90;
        }

        c1.surcharge = 0;
        if (c1.totalCharge > 300)
        {
            c1.surcharge = 15 * c1.totalCharge / 100;
            c1.totalCharge += c1.surcharge;
        }
        return c1;
    }

    void Display(Charge c1)
    {
        cout << "\n--- User Charges Summary ---\n";

        if (c1.totalCharge < 50)
        {
            cout << "User: " << name << "\nUnits Consumed: " << Cunits << "\nTotal Charges: Rs. " << 50 << endl;
        }
        else if (c1.surcharge)
        {
            cout << "User: " << name << "\nUnits Consumed: " << Cunits << "\nSurcharge Amount: Rs. " << c1.surcharge
                 << "\nTotal Charges: Rs. " << c1.totalCharge << endl;
        }
        else
        {
            cout << "User: " << name << "\nUnits Consumed: " << Cunits << "\nTotal Charges: Rs. " << c1.totalCharge << endl;
        }
    }
};

int main()
{
    string name;
    int units;

    for (int i = 0; i < 2; i++)
    {
        cout << "User " << i + 1 << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Units: ";
        cin >> units;

        generateBill User(name, units);
        Charge c1 = User.calculateAmount();
        User.Display(c1);
        cout << endl;
    }

    return 0;
}
