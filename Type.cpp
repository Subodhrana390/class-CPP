#include <iostream>
using namespace std;

// Class to basic
/*
class Time
{
    int hrs, mins;

public:
    Time(int a, int b)
    {
        hrs = a;
        mins = b;
    }

    operator int();
};

Time::operator int()
{
    return (hrs * 60 + mins);
}

void TypeCov(int hrs, int mins)
{
    int duration;
    Time t(hrs, mins);
    duration = t;

    cout << "1st Method " << duration << " mins" << endl;

    cout << "2nd MEthod ";
    duration = t.operator int();
    cout << duration << " mins" << endl;
}

int main()
{
    cout << "Vikram Yadav URN:2302708\n";
    int h = 4, min = 34;
    cout << "hr : " << h << " & min :" << min << endl;
    TypeCov(h, min);
    return 0;
}
*/

// basic to class
/*
class Time
{
    int hrs, mins;

public:
    Time(int t)
    {
        int duration = t;
        hrs = duration / 60;
        mins = duration % 60;
    }

    void convert()
    {

        cout << "Hours and Minutes = " << hrs << " hrs " << " & " << mins << " mins " << endl;
    }
};

int main()
{
    cout << "Vikram Yadav URN:2302708\n";
    Time t(356);
    t.convert();
}
*/
// class to class type coversion using constructor
/*
class Name
{
    string a;

public:
    Name()
    {
        a = "";
    }

    void getString()
    {
        cout << "Enter your string : ";
        getline(cin, a);
    }
    string get_String()
    {
        return a;
    }
    void show()
    {
        cout << "Given string at A is " << a << endl;
    }
};

class SubName
{
    string b;

public:
    SubName()
    {
        b = "";
    }
    SubName(Name &n)
    {
        b = n.get_String();
    }
    void show()
    {
        cout << "Given string at B is " << b << endl;
    }
};

int main()
{
    cout << "Subodh Rana URN:2302689\n";
    Name n;
    n.getString();
    n.show();
    SubName s(n);
    s.show();
}
*/
// class to class type coversion using casting operator

class Minutes
{
public:
    int mins;

    Minutes()
    {
        mins = 0;
    }
    void show()
    {
        cout << "Minutes M = " << mins << endl;
    }
};

class Time
{
    int hrs;
    int mins;

public:
    Time(int h, int m)
    {
        hrs = h;
        mins = m;
    }

    operator Minutes()
    {
        Minutes m;
        m.mins = (hrs * 60) + mins;
        return m;
    }
    void show()
    {
        cout << "Hours and Minutes = " << hrs << " & " << mins << endl;
    }
};

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Time t(4, 20);
    Minutes m;
    m = t;
    t.show();
    m.show();
}
/*
class Minutes
{
public:
    int mins;

    Minutes(int m)
    {
        mins = m;
    }
    void show()
    {
        cout << "Minutes M = " << mins << endl;
    }
};

class Time
{
    int hrs;
    int mins;

public:
    Time()
    {
        hrs = 0;
        mins = 0;
    }

    Time(Minutes &m)
    {
        hrs = m.mins / 60;
        mins = m.mins % 60;
    }
    void show()
    {
        cout << "Hours and Minutes = " << hrs << " & " << mins << endl;
    }
};

int main()
{
    cout << "SUBODH RANA URN:2302689\n";
    Minutes m(203);
    m.show();
    Time t(m);
    t.show();
}
*/