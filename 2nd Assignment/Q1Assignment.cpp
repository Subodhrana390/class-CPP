#include <iostream>
using namespace std;

class Staff
{
protected:
    int id;
    string fullName, department, salary, gender;
    bool isActive;
};

class Teacher : public Staff
{
public:
    void getTeacherDetails()
    {
        cout << "Enter Teacher's ID: ";
        cin >> id;
        cout << "Enter Full Name: ";
        cin >> fullName;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Active Status (1 for active, 0 for inactive): ";
        cin >> isActive;
    }
    void displayTeacherDetails()
    {
        cout << "ID: " << id << "\nName: " << fullName << "\nDepartment: " << department
             << "\nSalary: " << salary << "\nGender: " << gender << "\nActive: "
             << (isActive ? "Active" : "Inactive") << endl;
    }
};

class Typist : public Staff
{
public:
    void getTypistDetails()
    {
        cout << "Enter Typist's ID: ";
        cin >> id;
        cout << "Enter Full Name: ";
        cin >> fullName;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Active Status: ";
        cin >> isActive;
    }
    void displayTypistDetails()
    {
        cout << "ID: " << id << "\nName: " << fullName << "\nDepartment: " << department
             << "\nSalary: " << salary << "\nGender: " << gender << "\nActive: "
             << (isActive ? "Active" : "Inactive") << endl;
    }
};

class Regular : public Typist
{
    string type = "Regular";

public:
    void getRegularDetails()
    {
        getTypistDetails();
    }
    void displayRegularDetails()
    {
        displayTypistDetails();
        cout << "Type: " << type << endl;
    }
};

class Casual : public Typist
{
    string type = "Causal";

public:
    void getCasualDetails()
    {
        getTypistDetails();
    }
    void displayCasualDetails()
    {
        displayTypistDetails();
        cout << "Type: " << type << endl;
    }
};

class Officer : public Staff
{
public:
    void getOfficerDetails()
    {
        cout << "Enter Officer's ID: ";
        cin >> id;
        cout << "Enter Full Name: ";
        cin >> fullName;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Active Status: ";
        cin >> isActive;
    }
    void displayOfficerDetails()
    {
        cout << "ID: " << id << "\nName: " << fullName << "\nDepartment: " << department
             << "\nSalary: " << salary << "\nGender: " << gender << "\nActive: "
             << (isActive ? "Active" : "Inactive") << endl;
    }
};

int main()
{
    Teacher T1;
    Regular R1;
    Casual C1;
    Officer O1;
    int choice, action;
    do
    {
        cout << "Choices:\n1. Teacher\n2. Regular Typist\n3. Casual Typist\n4. Officer\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 4)
        {
            cout << "Action:\n1. Enter Details\n2. Display Details\nEnter your action choice: ";
            cin >> action;
        }
        switch (choice)
        {
        case 1:
            if (action == 1)
                T1.getTeacherDetails();
            else
                T1.displayTeacherDetails();
            break;
        case 2:
            if (action == 1)
                R1.getRegularDetails();
            else
                R1.displayRegularDetails();
            break;
        case 3:
            if (action == 1)
                C1.getCasualDetails();
            else
                C1.displayCasualDetails();
            break;
        case 4:
            if (action == 1)
                O1.getOfficerDetails();
            else
                O1.displayOfficerDetails();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
