# 计算机程序设计基础（2）作业（7）
**江玮陶    清华大学电子工程系**
## T5
```C++
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
    private:
        char name[11];
        char number[7];
        char sex[3];
        Date birthday;
        char id[16];

};
ostream &operator<<(ostream &output, People::Date&d){
    output<<'['<<d.year<<'/'<<d.month<<'/'<<d.day<<']';
    return output;
}
int main(){
    People *A= new People[3];
    People B1 ("alice","114514","nv",2024,4,9,"1919810");
    A[0]=B1;
    People B2("bob","12345","nan",2023,3,6,"1234567");
    A[1]=B2;
    A[2]=A[0];
    for(int i=0;i<=2;i++ ){
        A[i].print();
    }
    return 0;
}
```
## T6/7
```C++
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
```
## 附加题
```C++
#include<iostream>
using namespace std;
class Point{
    protected:
        double x,y;
    public:
        Point(double xx, double yy):x(xx),y(yy){
            cout<<*this<<"constructed!"<<endl;
        }
        Point(Point&p):x(p.x),y(p.y){
            cout<<*this<<"constructed!"<<endl;
        }
        ~Point(){
            cout<<*this<<"distructed!"<<endl;
        }
    friend ostream& operator<<(ostream&, Point&);
    friend class Segment;
};
class Segment{
    protected:
        Point* pA;
        Point* pB;
    public:
        Segment(Point *p1, Point *p2):pA(p1),pB(p2)
        {      
            cout<<*this<<"constructed!"<<endl;
        }
        Segment(Segment &s):pA(s.pA),pB(s.pB){
            cout<<*this<<"constructed"<<endl;
        }
        ~Segment(){
            cout<<*this<<"distructed!"<<endl;
        }
    friend ostream& operator<<(ostream&,Segment&);
};
class Rectangle{
    protected:
        Segment AB,BC,CD,DA;
    public:
        Rectangle(Point *A,Point*B,Point *C,Point *D):AB(A,B),BC(B,C),CD(C,D),DA(D,A){
            cout<<*this<<"constructed!"<<endl;
        }
        Rectangle(Rectangle &r):AB(r.AB),BC(r.BC),CD(r.CD),DA(r.DA){
            cout<<*this<<"constructed!"<<endl;
        }
        ~Rectangle(){
            cout<<*this<<"distructed!"<<endl;
        }
    friend ostream& operator<<(ostream&,Rectangle&);
};
ostream& operator<<(ostream&output, Point&p){
    output<<'('<<p.x<<' '<<p.y<<')';
    return output;
}
ostream& operator<<(ostream&output,Segment&s){
    output<<"line:"<<*s.pA<<"-"<<*s.pB;
    return output;
}
ostream& operator<<(ostream&output,Rectangle&r){
    output<<"Rectangle with:"<<endl<<r.AB<<endl<<r.BC<<endl<<r.CD<<endl<<r.DA<<endl;
    return output;
}
int main(){
    Point A(0,0),B(1,0),C(1,1),D(0,1);
    Rectangle R(&A,&B,&C,&D);
    cout<<R<<endl;
    return 0;
}
```
**输出信息**
```
(0 0)constructed!
(1 0)constructed!
(1 1)constructed!
(0 1)constructed!
line:(0 0)-(1 0)constructed!
line:(1 0)-(1 1)constructed!
line:(1 1)-(0 1)constructed!
line:(0 1)-(0 0)constructed!
Rectangle with:
line:(0 0)-(1 0)
line:(1 0)-(1 1)
line:(1 1)-(0 1)
line:(0 1)-(0 0)
constructed!
Rectangle with:
line:(0 0)-(1 0)
line:(1 0)-(1 1)
line:(1 1)-(0 1)
line:(0 1)-(0 0)

Rectangle with:
line:(0 0)-(1 0)
line:(1 0)-(1 1)
line:(1 1)-(0 1)
line:(0 1)-(0 0)
distructed!
line:(0 1)-(0 0)distructed!
line:(1 1)-(0 1)distructed!
line:(1 0)-(1 1)distructed!
line:(0 0)-(1 0)distructed!
(0 1)distructed!
(1 1)distructed!
(1 0)distructed!
(0 0)distructed!
```