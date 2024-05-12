#include<iostream>
#include<string.h>
using namespace std;
class Teacher;
class Student{
    private:
        int num;
        char name[10];
        bool sex;
    public:
        Student& operator=(Teacher );
        Student(int num, char*name, bool sex){
            this->num = num;
            this->sex = sex;
            strcpy(this->name, name);
        }
        void print(){
            cout<<"student:"<<name<<num<<sex<<endl;
        }
};
class Teacher{
    private:
        int num;
        char name[10];
        bool sex;
    public:
        friend Student;
        Teacher(int num, char*name, bool sex){
            this->num = num;
            this->sex = sex;
            strcpy(this->name, name);
        }
        void print(){
            cout<<"teacher:"<<name<<num<<sex<<endl;
        }
};
Student& Student::operator= (Teacher t){
    this->num = t.num;
    this->sex = t.sex;
    strcpy(this->name,t.name);
    return *this;
}

int main(){
    Teacher t(123,"asd",1);
    t.print();
    Student s(321,"qwe",0);
    s.print();
    s=t;
    s.print();
}