#include<iostream>
using namespace std;
#include<iostream>
#include<string.h>
using namespace std;
class People{
    public:
        class Date{
            public:
                int year;
                int month;
                int day;
                Date(int y=0,int m=0, int d=0):year(y),month(m),day(d){
                    cout<<"date"<<*this<<"constructed!"<<endl;
                    }
                Date(Date &d)
                {
                    month = d.month;
                    year = d.year;
                    day = d.day;
                    cout<<"date"<<*this<<"constructed!"<<endl;
                }
                ~Date(){
                    cout<<"date"<<*this<<"distructed!"<<endl;
                }
                friend ostream& operator<<(ostream&, Date &);
        };
        People(){cout<<"people default constructed"<<endl;}
        People(char*name, char*number, char*sex, int y,int m, int d, char*id){
            strcpy(this->name,name);
            strcpy(this->number,number);
            strcpy(this->sex,sex);
            strcpy(this->id,id);
            this->birthday=Date(y,m,d);
            cout<<this->name<<"constructed!"<<endl;
        }
        People(People &p){
            strcpy(this->name,p.name);
            strcpy(this->number,p.number);
            strcpy(this->sex,p.sex);
            strcpy(this->id,p.id);
            this->birthday = p.birthday;
            cout<<this->name<<"constructed!"<<endl;
        }
        ~People(){
            cout<<name<<"distructed!"<<endl;
        }
        void print(){
            cout<<name<<' '<<number<<' '<<sex<<' '<<birthday<<' '<<id<<endl;
        }
    protected:
        char name[11];
        char number[7];
        char sex[3];
        Date birthday;
        char id[16];

};
class Student : virtual public People{
    protected:
        char classNo[7];
    public:
        Student(char*classNo,char*name, char*number, char*sex, int y,int m, int d, char*id):People(name,number,sex,y,m,d,id){
            strcpy(this->classNo,classNo);
        }
        ~Student(){
            cout<<"Student"<<name<<"killed!"<<endl;
        }
        void print(){
            cout<<"student:";
            People::print();
            cout<<"@"<<classNo<<endl;
        }
};
class Teacher : virtual public People{
    protected:
        char principalship[11];
        char department[21];
    public:
        Teacher(char*principalship,char*department,char*name, char*number, char*sex, int y,int m, int d, char*id):People(name,number,sex,y,m,d,id){
            strcpy(this->principalship,principalship);
            strcpy(this->department,department);
        }
        Teacher(Teacher &t):People(t){
            strcpy(this->principalship,t.principalship);
            strcpy(this->department,t.department);
        }
        ~Teacher(){
            cout<<"Teacher"<<name<<"killed!"<<endl;
        }
        void print(){
            cout<<"Teacher:";
            People::print();
            cout<<principalship<<'@'<<department<<endl;
        }
};
class Graduate : public Student{
    protected:
        char subject[21];
        Teacher advisor;
    public:
        Graduate(char*subject,Teacher &adv,char*classNo,char*name, char*number, char*sex, int y,int m, int d, char*id):advisor(adv),Student(classNo,name,number,sex,y,m,d,id){
            strcpy(this->subject,subject);
        }
        ~Graduate(){
            cout<<"Graduate"<<name<<"killed!!"<<endl;
        }
        void print(){
            cout<<"Graduate_";
            Student::print();
            cout<<"subject"<<subject<<endl;
            cout<<"with advisor:"<<endl;
            advisor.print();
        }
};
class TA: public Teacher,public Graduate{
    public:
        TA (char*principalship,char*department,char*subject,Teacher &adv,char*classNo,char*name, char*number, char*sex, int y,int m, int d, char*id):Teacher(principalship,department,name,number,sex,y,m,d,id),Graduate(subject,adv,classNo,name,number,sex,y,m,d,id){}
        void print(){
            cout<<"TA"<<endl;
            Teacher::print();
            Graduate::print();
        }
};
ostream &operator<<(ostream &output, People::Date&d){
    output<<'['<<d.year<<'/'<<d.month<<'/'<<d.day<<']';
    return output;
}

int main(){
    Student sA ("ee36","alice","114514","nv",2024,1,1,"123456778");
    Teacher tA ("principal","EECS","XiqinWang","1919810","nan",1999,1,1,"23456789");
    Graduate gA("EECS",tA,"12345678","bob","2341223","nan",2000,2,3,"1234");
    Teacher tB("teacher","SMS","cindy","1234455","nv",1993,2,2,"12345");
    TA taA ("phd","EECS","EE",tB,"ee36","aaaa","198964","nan",2020,4,4,"12343442");
    sA.print();
    tA.print();
    gA.print();
    tB.print();
    taA.print();
    return 0;
}