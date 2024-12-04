#include <iostream>
using namespace std;

// Single inheritance
/*
class Parent
{
protected:
    int id_p;

public:
    void getID_p(int id)
    {
        id_p = id;
    }
    void printID_p()
    {
        cout << "Base ID: " << id_p << endl;
    }
};

class Child : public Parent
{
protected:
    int id_c;

public:
    void getID_c(int id)
    {
        id_c = id;
    }
    void printID_c()
    {
        cout << "Derived ID: " << id_c << endl;
    }
};

int main()
{
    cout << "Subodh Rana URN:2302689\n";
    Child obj1;
    obj1.getID_c(34);
    obj1.getID_p(32);
    obj1.printID_c();
    obj1.printID_p();
    return 0;
}
*/
// Multiple  Inheritance
/*
class Vehicles
{
protected:
    string vehicleName;

public:
    Vehicles(string name = "Generic")
    {
        vehicleName = name;
    }
    void showName()
    {
        cout << "Vehicle Name : " << vehicleName << endl;
    }
};

class FourWheeler
{
protected:
    int wheels;

public:
    FourWheeler(int w = 4) { wheels = w; }
    void showWheels()
    {
        cout << "Number of Wheels : " << wheels << endl;
    }
};

class Car : public Vehicles, public FourWheeler
{
public:
    void VehicleInfo()
    {
        cout
            << "Vehcicles whose named " << vehicleName << " have " << wheels << " Wheels " << endl;
    }
};

int main()
{
    Car obj;
    obj.showName();
    obj.showWheels();
    obj.VehicleInfo();
    return 0;
}
*/

/*
class Vehicles
{
protected:
    string vehicleName;

public:
    Vehicles(string name = "Generic")
    {
        vehicleName = name;
    }
    void showName()
    {
        cout << "Vehicle Name : " << vehicleName << endl;
    }
};

class FourWheeler
{
protected:
    int wheels;

public:
    FourWheeler(int w = 4) { wheels = w; }
    void showWheels()
    {
        cout << "Number of Wheels : " << wheels << endl;
    }
};

class Car : public Vehicles, public FourWheeler
{
public:
    void VehicleInfo()
    {
        cout << "Vehicles whose named " << vehicleName << " have " << wheels << " Wheels " << endl;
    }
};

int main()
{
    Car obj;
    obj.showName();
    obj.showWheels();
    obj.VehicleInfo();
    return 0;
}

*/
// Multi Level Inheritance
/*
class Bank
{
protected:
    string BankName;
    string branch;

public:
    void getBankDetails()
    {
        cout << "Enter your Bank : ";
        getline(cin, BankName);
        cout << "Enter your Branch: ";
        getline(cin, branch);
    }
};

class Dept : public Bank
{
public:
    string DeptName;
    int NofEmp;
    void getDeptInfo()
    {
        cout << "Enter your department :";
        getline(cin, DeptName);
        cout << "Enter Total Employee of this Dept :";
        cin >> NofEmp;
    }
};

class Employees : public Dept
{
protected:
    int id;
    string EmpName;

public:
    void getEmpDetails()
    {
        cout << "Enter Employee ID : ";
        cin >> id;
        cout << "Enter Employee Name : ";
        cin >> EmpName;
    }

    void ShowEmployeeDetails()
    {

        cout << "\n\nEmployee Details: " << endl;
        cout << "Bank Name :" << BankName << endl;
        cout << "Bank Branch :" << branch << endl;
        cout << "Bank Department :" << DeptName << endl;
        cout << "No of Employee in Department :" << NofEmp << endl;
        cout << "Employee Details :" << endl;
        cout << "Employee Id : " << id << endl;
        cout << "Employee Name : " << EmpName << endl;
    }
};

int main()
{
    Employees E1;
    E1.getBankDetails();
    E1.getDeptInfo();
    E1.getEmpDetails();
    E1.ShowEmployeeDetails();
    return 0;
}
*/

// Hierarchical Inheritance
/*
class Vehicle
{
protected:
    string vehicleName;
    int wheels;
    double price;
    string color;

public:
    Vehicle(string name = "Generic", int w = 4, double p = 0, string c = "Black") {}

    void getDetails()
    {
        cout << "Enter Vehicle Name : ";
        getline(cin, vehicleName);
        cout << "Enter Wheels : ";
        cin >> wheels;
        cout << "Enter Price : ";
        cin >> price;
        cout << "Enter Color : ";
        cin >> color;
    }
    void showDetails()
    {
        cout << "Vehicle Name : " << vehicleName << endl;
        cout << "Wheels : " << wheels << endl;
        cout << "Price : $" << price << endl;
        cout << "Color : " << color << endl;
    }
};

class Car : public Vehicle
{
protected:
    string brand;
    int seats;
    int doors;

public:
    Car(string b = "Unknown", int s = 0, int d = 0)
    {
    }

    void getCarDetails()
    {
        Vehicle::getDetails();
        cin.ignore();
        cout << "Enter Brand : ";
        getline(cin, brand);
        cout << "Enter Seats : ";
        cin >> seats;
        cout << "Enter Doors : ";
        cin >> doors;
    }

    void showCarDetails()
    {
        cout << "================================ Show Car Details================================";
        Vehicle::showDetails();
        cout << "Brand : " << brand << endl;
        cout << "Seats : " << seats << endl;
        cout << "Doors : " << doors << endl;
    }
};

class Bus : public Vehicle
{
protected:
    int seats;
    string type;
    int capacity;

public:
    Bus() : Vehicle(), seats(50), type("Sleeper"), capacity(500) {}

    void getBusDetails()
    {
        Vehicle::getDetails();
        cout << "Enter Seats : ";
        cin >> seats;
        cout << "Enter Type : ";
        cin >> type;
        cout << "Enter Capacity : ";
        cin >> capacity;
    }
    void showBusDetails()
    {
        cout << "========================= Show Bus Details =================";
        Vehicle::showDetails();
        cout << "Seats : " << seats << endl;
        cout << "Type : " << type << endl;
        cout << "Capacity : " << capacity << endl;
    }
};

int main()
{
    Car obj1;
    obj1.getCarDetails();
    obj1.showCarDetails();
    cout << "\n\nBus";
    Bus obj2;
    obj2.getBusDetails();
    obj2.showBusDetails();
}
*/
// Hybrid Inheritance
class Meter
{
public:
    // Convert cm to meters
    double convertToMeters(double lengthUnit)
    {
        return lengthUnit / 100.0;
    }
};

class Inches
{
public:
    int iLen;
    void getInches()
    {
        cout << "Enter length in inches: ";
        cin >> iLen;
    }

    // Convert cm to inches
    double convertToInches(double lengthUnit)
    {
        return lengthUnit / 2.54;  // 1 inch = 2.54 cm
    }
};

class lengthConverter : public Meter, public Inches
{
public:
    void Converter()
    {
        double length;
        cout << "Enter length in cm: ";
        cin >> length;
        cout << "1. Convert to meters\n2. Convert to inches\n";
        
        int choice;
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "Length in meters: " << convertToMeters(length) << endl;
        }
        else if (choice == 2)
        {
            cout << "Length in inches: " << convertToInches(length) << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
};

class InchToMeter : public lengthConverter
{
public:
    void inchesToMeter()
    {
        double meters = iLen * 0.0254;  // Convert inches to meters (1 inch = 0.0254 meters)
        cout << "Length in meters: " << meters << " meter(s)" << endl;
    }
};

int main()
{
    InchToMeter M;
    M.Converter();
    M.getInches();
    M.inchesToMeter();
    
    return 0;
}