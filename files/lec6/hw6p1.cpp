#include<bits/stdc++.h>
using namespace std;
class Person{
    protected:
        char* name;
        char sex;
        int age;
    public:
        Person(char* name, char sex, int age){
            this->name = new char[20];
            strcpy(this->name, name);
            this->sex = sex;
            this->age = age;
        }
};
class Employee :public Person{
    protected:
        int basicSalary;
        int leaveDays;
    public:
        void show(){
            cout<<name<<endl<<sex<<endl<<age<<endl;
            cout<<basicSalary<<endl<<leaveDays<<endl;
        }
        Employee(char* name, char sex, int age, int bS, int lD):Person(name, sex, age){
            basicSalary = bS;
            leaveDays = lD;
        }
};
class Manager :public Employee{
    protected:
        double performance;
    public:
        void show(){
            Employee::show();
            cout<<performance<<endl;
        }
        Manager(char* name, char sex, int age, int bS, int lD, double performance ):Employee(name,sex,age,bS,lD){
            this->performance =performance;
        }
};
int main(){
    char* name;
    name = new char[20];
    char sex;
    int age;
    int bs;
    int ld;
    double per;
    cin>>name;
    cin>>sex>>age>>bs>>ld>>per;
    Manager a(name,sex,age,bs,ld,per);
    a.show();
    delete[] name;
    return 0;
}