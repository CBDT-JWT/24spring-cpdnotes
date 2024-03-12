#include <iostream>

#include <iomanip>

using namespace std;

class Date

{

    int d, m, y;

public:
    Date(int dd = 0, int mm = 0, int yy = 0);

    Date(const Date &D); // 拷贝构造函数

    ~Date();
};

Date::Date(int dd, int mm, int yy) : d(dd), m(mm), y(yy)

{

    cout << "Constructor Called! Address = 0x" << hex << setw(8) << setfill('0') << this << endl;
}

Date::Date(const Date &D)

{

    d = D.d;

    m = D.m;

    y = D.y;

    cout << "Copy Constructor Called! Address = 0x" << hex << setw(8) << setfill('0') << this << endl;
}

Date::~Date()

{

    cout << "Destructor Called! Address = 0x" << hex << setw(8) << setfill('0') << this << endl;
}

Date func(Date A)

{

    return Date(A);
}

int main()

{

    Date today;

    today = func(today);

    return 0;
}