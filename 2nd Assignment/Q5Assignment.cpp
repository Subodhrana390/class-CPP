#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream file3("file3.txt");
    if (!file1.is_open() || !file2.is_open() || !file3.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }
    char ch;
    while (file1.get(ch)) {
        file3.put(ch);
    }
    while (file2.get(ch)) {
        file3.put(ch);
    }
    file1.close();
    file2.close();
    file3.close();
    cout << "Contents copied from file1.txt and file2.txt to file3.txt successfully." << endl;
    return 0;
}
