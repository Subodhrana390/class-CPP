#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <sstream>

using namespace std;

class LibraryItem {
public:
    string name, creator, uniqueID;
    bool isOnLoan;

    LibraryItem(string n, string c, string id)
        : name(n), creator(c), uniqueID(id), isOnLoan(false) {}

    void showDetails() {
        cout << "Title: " << name << ", Creator: " << creator
             << ", ID: " << uniqueID << ", Status: "
             << (isOnLoan ? "Checked Out" : "Available") << endl;
    }

    bool lendItem() {
        if (isOnLoan) return false;
        isOnLoan = true;
        return true;
    }

    bool returnItem() {
        if (!isOnLoan) return false;
        isOnLoan = false;
        return true;
    }

    string getName() { return name; }
    bool isAvailable() { return !isOnLoan; }
};

class Member {
public:
    string userID, passcode;

    Member(string id, string pass)
        : userID(id), passcode(pass) {}

    bool verify(string inputPass) { return inputPass == passcode; }
};

class MemberManager {
private:
    map<string, Member> memberRegistry;

public:
    void ensureMembersFileExists(string fileName) {
        ifstream testFile(fileName);
        if (!testFile) {
            ofstream outFile(fileName);
            if (outFile) {
                outFile << "admin,admin123\nuser1,pass1\nuser2,pass2\n";
                cout << "Sample members file created: " << fileName << endl;
            }
        }
    }

    void loadMembersFromFile(string fileName) {
        ensureMembersFileExists(fileName);
        ifstream inputFile(fileName);
        string line;
        while (getline(inputFile, line)) {
            stringstream lineStream(line);
            string id, pass;
            getline(lineStream, id, ',');
            getline(lineStream, pass);
            memberRegistry.emplace(id, Member(id, pass));
        }
    }

    bool authenticateUser(string userID, string passcode) {
        auto it = memberRegistry.find(userID);
        if (it != memberRegistry.end()) {
            return it->second.verify(passcode);
        }
        return false;
    }
};

class LibrarySystem {
private:
    vector<shared_ptr<LibraryItem>> catalog;

public:
    void addItem(shared_ptr<LibraryItem> item) {
        catalog.push_back(item);
    }

    void showAvailableItems() {
        for (auto &item : catalog) {
            if (item->isAvailable()) {
                item->showDetails();
            }
        }
    }

    shared_ptr<LibraryItem> findItem(string itemName) {
        for (auto &item : catalog) {
            if (item->getName() == itemName) {
                return item;
            }
        }
        return nullptr;
    }

    bool lendItem(string itemName) {
        auto item = findItem(itemName);
        if (item && item->isAvailable()) {
            return item->lendItem();
        }
        return false;
    }

    bool returnItem(string itemName) {
        auto item = findItem(itemName);
        if (item && !item->isAvailable()) {
            return item->returnItem();
        }
        return false;
    }

    void saveCatalogToFile(string fileName) {
        ofstream outputFile(fileName);
        for (auto &item : catalog) {
            outputFile << item->getName() << ","
                       << item->creator << ","
                       << item->uniqueID << ","
                       << (item->isAvailable() ? "0" : "1") << "\n";
        }
    }

    void loadCatalogFromFile(string fileName) {
        ifstream inputFile(fileName);
        string line;
        while (getline(inputFile, line)) {
            stringstream lineStream(line);
            string name, creator, uniqueID, status;
            getline(lineStream, name, ',');
            getline(lineStream, creator, ',');
            getline(lineStream, uniqueID, ',');
            getline(lineStream, status, ',');
            auto item = make_shared<LibraryItem>(name, creator, uniqueID);
            if (status == "1") {
                item->lendItem();
            }
            catalog.push_back(item);
        }
    }
};

int main() {
    LibrarySystem library;
    MemberManager memberManager;

    memberManager.loadMembersFromFile("members.txt");
    library.loadCatalogFromFile("catalog.txt");

    string userID, passcode;
    cout << "Enter user ID: ";
    cin >> userID;
    cout << "Enter passcode: ";
    cin >> passcode;

    if (!memberManager.authenticateUser(userID, passcode)) {
        cerr << "Authentication failed!" << endl;
        return 1;
    }

    int menuOption;
    do {
        cout << "\n1. Add Item\n2. View Available Items\n3. Lend Item\n4. Return Item\n5. Save Catalog\n6. Exit\n";
        cin >> menuOption;

        switch (menuOption) {
        case 1: {
            string name, creator, uniqueID;
            cout << "Enter item name, creator, and unique ID: ";
            cin.ignore();
            getline(cin, name);
            getline(cin, creator);
            getline(cin, uniqueID);
            library.addItem(make_shared<LibraryItem>(name, creator, uniqueID));
            break;
        }
        case 2:
            library.showAvailableItems();
            break;
        case 3: {
            string itemName;
            cout << "Enter item name to lend: ";
            cin.ignore();
            getline(cin, itemName);
            if (library.lendItem(itemName)) {
                cout << itemName << " has been lent." << endl;
            } else {
                cout << itemName << " could not be lent." << endl;
            }
            break;
        }
        case 4: {
            string itemName;
            cout << "Enter item name to return: ";
            cin.ignore();
            getline(cin, itemName);
            if (library.returnItem(itemName)) {
                cout << itemName << " has been returned." << endl;
            } else {
                cout << itemName << " could not be returned." << endl;
            }
            break;
        }
        case 5:
            library.saveCatalogToFile("catalog.txt");
            cout << "Catalog saved to file." << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (menuOption != 6);

    return 0;
}
