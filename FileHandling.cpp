#include <bits/stdc++.h>
using namespace std;

// int main()
// {

//     ifstream fin;
//     fin.open("zero.txt");
//     char c;
//     while (fin >> c)
//     {
//         cout << c;
//     }

//     int arr[5];
//     cout << "Enter the input: ";
//     for (int i = 0; i < 5; i++)
//     {
//         cin >> arr[i];
//     }

//     ofstream fout;
//     fout.open("zero.txt");
//     fout << "Original Data\n";
//     for (int i = 0; i < 5; i++)
//     {
//         fout << arr[i] << " ";
//     }
//     fout << "\nSorted data:\n";
//     sort(arr, arr + 5);
//     for (int i = 0; i < 5; i++)
//     {
//         fout << arr[i] << " ";
//     }
//     fout.close();
//     return 0;
// }

// int main()
// {
//     ofstream fout;
//     fout.open("z1.txt");
//     fout << "Hello India\n";
//     fout << "Hello Rohit\n";
//     fout << "Hello Bhai\n";
//     fout.close();

//     ifstream fin;
//     fin.open("z1.txt");

//     string line;
//     while (getline(fin, line)){
//         cout<<line<<endl;
//     }
//     fin.close();
//     return 0;
// }

int main()
{
    ifstream fin;

    fin.open("z1.txt");

    char c;
    fin >> c;
    // c = fin.get();
    while (!fin.eof())
    // while (fin)
    {
        cout << c;
        fin >> c;
        // c = fin.get();
    }
    fin.close();
    return 0;
}