#include<iostream>
#include<string.h>
using namespace std;
class People{
    public :
    class Date{
            private:
                int year;
                int month;
                int day;
            public:
                Date(int y, int m, int d){
                    year = y;
                    month = m;
                    day = d;
                }
                Date(const Date &d){
                    day= d.day;
                    month = d.month;
                    year = d.year;
                }
                void print(){
                    cout << year << "/" << month << "/" << day << endl;
                }
        };
    private:
        
        char name[11];
        char number[7];
        char sex[3];
        Date birthday;
        char id[16];
    public:
    

        People(char*name, char*number, char*sex, int y, int m, int d, char*id):birthday(y,m,d){
            strcpy(this->name, name);
            strcpy(this->number, number);
            strcpy(this->sex,sex);
            //birthday = new Date(y,m,d);
            strcpy(this->id, id);
        }
        void print(){
            printf("%s,%s,%s,%s",this->name,this->id,this->sex,this->number);
            this->birthday.print();
        }
};
int main(){
    People p1("yx","1234","nv",2024,3,26,"12345678");
    p1.print();
}