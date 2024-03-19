# 程序设计基础(2)作业3
**江玮陶**  *清华大学电子工程系*

## 习题7
**SOLUTION**

```C++
#include<iostream>
using namespace std;
class STUDENT {
    private:
        int num;
        int grade;
    public:
        STUDENT(int n, int g){
            num = n;
            grade = g;
        }
        int get_num(){
            return num;
        }
        int get_grade(){
            return grade;
        }
        void set_num(int n){
            num = n;
        }
        void set_grade(int g){
            grade = g;
        }

};

STUDENT students[5] = {STUDENT(1, 90), STUDENT(2, 80), STUDENT(3, 70), STUDENT(4, 60), STUDENT(5, 50)};
STUDENT *pStudent = students;

int main(){
    for(int i = 0; i<5; i+=2){
        cout<<pStudent->get_num()<<" "<<pStudent->get_grade()<<endl;
        pStudent+=2;
    }
    return 0;
}
```

## 习题8
**SOLUTION**

```C++
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
class STUDENT{
    private:
        int num;
        int grade;
        char* name;
    public:
        STUDENT (int n, int g, char* nm){
            set_num(n);
            set_grade(g);
            set_name(nm);
        }
        STUDENT(const STUDENT& s) {
            num = s.num;
            grade = s.grade;
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }
        int get_num(){
            return num;
        }
        int get_grade(){
            return grade;
        }
        char* get_name(){
            return name;
        }
        void set_num(int n){
            num = n;
        }
        void set_grade(int g){
            grade = g;
        }
        void set_name(char* n){
            name = n;
        }
};

STUDENT* get_Max(STUDENT* pBegin, int n){
    int maxGrade = -INF;
    STUDENT* pmax_student = pBegin;
    for(int i = 0; i<n; i++){
        if(pBegin[i].get_grade()>maxGrade){
            maxGrade = pBegin[i].get_grade();
            pmax_student = pBegin+i;
        }
    }
    return pmax_student;
}

int main(){
    STUDENT students[10] ={STUDENT(2024010001,90,"Alice"),STUDENT(2024010002,80,"Bob"),STUDENT(2024010003,70,"Cindy"),STUDENT(2024010004,60,"David"),STUDENT(2024010005,50,"Eva"),STUDENT(2024010006,40,"Frank"),STUDENT(2024010007,30,"Grace"),STUDENT(2024010008,20,"Helen"),STUDENT(2024010009,10,"Ivy"),STUDENT(2024010010,0,"Jack")};
    STUDENT* pStudent = students;
    STUDENT* pmax_student = get_Max(pStudent, 5);
    cout<<pmax_student->get_num()<<" "<<pmax_student->get_grade()<<" "<<pmax_student->get_name()<<endl;
    return 0;
}
```

## 类的组合练习

>先声明一个点类`Point`，成员为其坐标x，y，并设计构造函数（可赋初值也可以不赋初值）、复制构造函数、析构函数（打印信息，表示其被调用），设置新值函数`Set`, 打印成员坐标值函数`Print`.再声明一个矩形类`Rectangle`，其成员为矩形的左下角和右上角两个`Point`对象，并设计`Rectangle`构造函数（分别由x1，y1，x2，y2坐标值构造，或由p1，p2两个点对象构造，可赋初值也可以不赋初值）、复制构造函数、析构函数（打印信息，表示其被调用），设置新值函数`Set`, 打印成员值函数Print，计算矩形面积函数`Area`，以及其它你认为对访问此类对象有用的成员函数。并用此`Rectangle`类定义对象，调用所有成员函数.

**Solution**

```C++
#include<iostream>
using namespace std;
class POINT {
    private:
        int x;
        int y;
    public:
        POINT(int x, int y){
            this->x = x;
            this->y = y;
        }
        POINT(){
            x = 0;
            y = 0;
        }
        POINT(const POINT& p){
            x = p.x;
            y = p.y;
        }
        ~POINT(){
            cout<<"POINT destructor"<<endl;
        }
        void SET(int x, int y){
            this->x = x;
            this->y = y;
        }
        void Print(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }
};
class RECTANGLE {
    private:
        POINT p1;
        POINT p2;
    public:
        RECTANGLE(int x1, int y1, int x2, int y2){
            p1.SET(x1, y1);
            p2.SET(x2, y2);
        }
        RECTANGLE(){
            p1.SET(0, 0);
            p2.SET(0, 0);
        }
        RECTANGLE(const RECTANGLE& r){
            p1 = r.p1;
            p2 = r.p2;
        }
        ~RECTANGLE(){
            cout<<"RECTANGLE destructor"<<endl;
        }
        void SET(int x1, int y1, int x2, int y2){
            p1.SET(x1, y1);
            p2.SET(x2, y2);
        }
        void Print(){
            cout<<"p1: ";
            p1.Print();
            cout<<"p2: ";
            p2.Print();
        }
        int Area(){
            return (p2.get_x()-p1.get_x())*(p2.get_y()-p1.get_y());
        }
};
int main(){
    RECTANGLE r1(1, 1, 3, 3);
    RECTANGLE r2(r1);
    r1.Print();
    r2.Print();
    cout<<r1.Area()<<endl;
    cout<<r2.Area()<<endl;
    return 0;
}
```


## 选做题
>在前述“类的组合练习”中，在Point类和Rectangle类中的构造函数和复制构造函数函数中，打印信息，并根据输出结果分析构造函数,复制构造函数与析构函数的调用时机

**Solution**

```C++
#include<iostream>
using namespace std;
class POINT {
    private:
        int x;
        int y;
    public:
        POINT(int x, int y){
            this->x = x;
            this->y = y;
        }
        POINT(){
            x = 0;
            y = 0;
            printf("(%d,%d)'s ", x, y);
            cout<<"POINT constructor called"<<endl;
        }
        POINT(const POINT& p){
            x = p.x;
            y = p.y;
            printf("(%d,%d)'s ", x, y);
            cout<<"POINT copy constructor called"<<endl;
        }
        ~POINT(){
            printf("(%d,%d)'s ", x, y);
            cout<<"POINT destructor called"<<endl;
        }
        void SET(int x, int y){
            this->x = x;
            this->y = y;
        }
        void Print(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }
};
class RECTANGLE {
    private:
        POINT p1;
        POINT p2;
    public:
        RECTANGLE(int x1, int y1, int x2, int y2){
            p1.SET(x1, y1);
            p2.SET(x2, y2);

        }
        RECTANGLE(){
            p1.SET(0, 0);
            p2.SET(0, 0);
            printf("(%d,%d),(%d,%d) 's ", p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
            cout<<"RECTANGLE constructor called"<<endl;
        }
        RECTANGLE(const RECTANGLE& r){
            p1 = r.p1;
            p2 = r.p2;
            printf("(%d,%d),(%d,%d) 's ", p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
            cout<<"RECTANGLE copy constructor called"<<endl;
        }
        ~RECTANGLE(){
            printf("(%d,%d),(%d,%d) 's ", p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
            cout<<"RECTANGLE destructor called"<<endl;
        }
        void SET(int x1, int y1, int x2, int y2){
            p1.SET(x1, y1);
            p2.SET(x2, y2);
        }
        void Print(){
            cout<<"p1: ";
            p1.Print();
            cout<<"p2: ";
            p2.Print();
        }
        int Area(){
            return (p2.get_x()-p1.get_x())*(p2.get_y()-p1.get_y());
        }
};
int main(){
    RECTANGLE r1(1, 1, 3, 3);
    RECTANGLE r2(r1);
    r1.Print();
    r2.Print();
    cout<<r1.Area()<<endl;
    cout<<r2.Area()<<endl;
    return 0;
}
```

**Output**

>(0,0)'s POINT constructor called
>(0,0)'s POINT constructor called
>(0,0)'s POINT constructor called
>(0,0)'s POINT constructor called
>(1,1),(3,3) 's RECTANGLE copy constructor called
>p1: (1,1)
>p2: (3,3)
>p1: (1,1)
>p2: (3,3)
>4
>4
>(1,1),(3,3) 's RECTANGLE destructor called
>(3,3)'s POINT destructor called
>(1,1)'s POINT destructor called
>(1,1),(3,3) 's RECTANGLE destructor called
>(3,3)'s POINT destructor called
>(1,1)'s POINT destructor called

**Analysis**

构造`RECTANGLE`对象的时候调用了p1和p2的默认构造函数(0,0),而后用(1,1),(3,3)赋值时由于采用`set`函数的方法,没有调用`POINT`类的构造函数/复制构造函数.此后使用`RECTANGLE`的复制构造函数为r2赋值.最后依次析构r2和r1.

>根据例3-24和例3-25，改进程序，尽可能减少构造函数和复制构造函数的调用次数。写出你的改进方法。

**Answer**

可以通过使用`set()`函数替代复制构造函数,以及通过对象引用而不是形参的方式进行函数传参进而避免复制构造函数的多次调用.