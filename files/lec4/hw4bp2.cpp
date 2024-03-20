#include<iostream>
using namespace std;
class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void print(){
            cout << day << "/" << month << "/" << year << endl;
        }
        void operator++ ();
        void operator++ (int);
};

void Date:: operator ++ (){
    if(day == 28&&month == 2&&(year%4!=0 || (year%100==0 && year%400!=0))){
        day = 1;
        month = 3;
    }
    else if(day == 29&&month == 2){
        day = 1;
        month = 3;
    }
    else if(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        day = 1;
        month++;
    }
    else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
        day = 1;
        month++;
    }
    else if(day == 31 && month == 12){
        day = 1;
        month = 1;
        year++;
    }
    else{
        day++;
    }
    return;
}
void Date::operator++ (int){
    if(day == 28&&month == 2&&(year%4!=0 || (year%100==0 && year%400!=0))){
        day = 1;
        month = 3;
    }
    else if(day == 29&&month == 2){
        day = 1;
        month = 3;
    }
    else if(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        day = 1;
        month++;
    }
    else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
        day = 1;
        month++;
    }
    else if(day == 31 && month == 12){
        day = 1;
        month = 1;
        year++;
    }
    else{
        day++;
    }
    return;
}
int main(){
    Date date(31,12,2020);
    date++;
    date.print();
    ++date;
    date.print();
    return 0;
}