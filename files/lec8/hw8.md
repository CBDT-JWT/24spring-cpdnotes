# 计算机程序设计基础（2）作业8
**江玮陶**
**清华大学电子工程系**
## p512Question10
**分析如下程序运行结果**
```C++
#include<iostream>
using namespace std;
class B{
    public:
        void f1(){
            cout<<"B::f1"<<endl;
        }
};
class D: public B{
    public:
        void f1(){
            cout<<"D::f1"<<endl
        }
};
void f(B& rb){
    rb.f1();
}
int main(){
    D d;
    B b, &rb1=b,&rb2=d;
    f(rb1);
    f(rb2);
    return 0;
}
```

**预期输出：**
```
B::f1
B::f1
```
## p532-534Question6
**代码**
```C++
#include<iostream>
using namespace std;
class Mammal{
    public:
        virtual void speak()=0;
};
class Dog: public Mammal{
    public:
    void speak(){
        cout<<"dog::speak() called!"<<endl;
    }
};
int main(){
    Dog Siqi;
    Siqi.speak();
    return 0;
}
```
**输出**
```
dog::speak() called!
```
## P532-534Question8
**代码**
```C++

#include<iostream>
using namespace std;
class Shape{
    public:
        Shape(){}
        ~Shape(){}
        virtual float GetArea()=0;
        virtual float GetPerim()=0;
};
class Rectangle: public Shape{
    protected:
        double la,lb;
    public:
        Rectangle(double a,double b):la(a),lb(b){
            cout<<"Rectangle constructed!"<<endl;
        }
        ~Rectangle(){
            cout<<"Rectangle disconstructed!"<<endl;
        }
        float GetArea(){
            return la*lb;
        }
        float GetPerim(){
            return 2*(la+lb);
        }

};
class Circle: public Shape{
    protected:
        double r;
    public:
        Circle(double rad):r(rad){
            cout<<"Circle constructed!"<<endl;
        }
        ~Circle(){
            cout<<"Circle distructed!"<<endl;
        }
        float GetArea(){
            return 3.1416*r*r;
        }
        float GetPerim(){
            return 2*3.1416*r;
        }
};
int main(){
    Rectangle r1(11,22);
    Circle c1(2);
    Shape* ptr[2] = {&r1,&c1};
    for(int i = 0; i<=1; i++){
        cout<<ptr[i]->GetArea()<<endl;
        cout<<ptr[i]->GetPerim()<<endl;
    }
    return 0;
}
```
**输出**
```
Rectangle constructed!
Circle constructed!
242
66
12.5664
12.5664
Circle distructed!
Rectangle disconstructed!
```
## 附加题
回顾上一讲附加题，通过继承方式实现了点、线、矩阵类，请考虑在此基础上实现下列功能
1. 定义抽象类`shape`，包含求面积函数和输出函数，其中输出函数用纯虚函数实现
2. 除了矩阵类之外，再派生出三角类和圆类；这些派生类中输出函数用于说明派生类是什么形状
3. 在主函数中，使用基函数指针数组，分别调用不同类实体

**代码**

```C++
#include<bits/stdc++.h>
using namespace std;
class Shape{
    public:
        ~Shape(){};
        Shape(){};
        virtual void Show()=0;
        virtual double GetArea()=0;
};
class Point : virtual public Shape{
    protected:
        double xPos, yPos;
    public:
        ~Point(){
            cout<<"Point destructed!"<<endl;
        }
        Point(double x,double y):xPos(x),yPos(y){
            cout<<"Point constructed!"<<endl;
        }
        Point(Point &p):xPos(p.xPos),yPos(p.yPos){
            cout<<"Point constructed!"<<endl;
        }
        double GetArea(){
            return 0;
        }
        void Show(){
            cout<<"Point:("<<xPos<<","<<yPos<<")"<<endl;
            return;
        }
    friend class Line;
};
class Line : virtual public Shape{
    protected:
        Point A,B;
    public:
        ~Line(){
            cout<<"Line destructed!"<<endl;
        }
        Line(Point&src, Point&dst):A(src),B(dst){
            cout<<"Line constructed!"<<endl;
        }
        Line(Line&l):A(l.A),B(l.B){
            cout<<"Line constructed!"<<endl;
        }
        double GetArea(){
            return 0;
        }
        double GetLen(){
            return sqrt((A.xPos-B.xPos)*(A.xPos-B.xPos)+(A.yPos-B.yPos)*(A.yPos-B.yPos));
        }
        void Show(){
            cout<<"Line from"<<endl<<"  ";
            A.Show();
            cout<<"to"<<endl<<"  ";
            B.Show();
        }
};

class Rectangle: virtual public Shape{
    protected:
        Point A,B,C,D;
        Line AB,BC,CD,DA;
    public:
        ~Rectangle(){
            cout<<"Rectangle destructed!"<<endl;
        }
        Rectangle(Point a, Point b, Point c, Point d):A(a),B(b),C(c),D(d),AB(a,b),BC(b,c),CD(c,d),DA(d,a){
            cout<<"Rectangle constructed!"<<endl;
        }
        void Show(){
            cout<<"Rectangle with points:"<<endl<<"  ";
            A.Show();
            cout<<"  ";
            B.Show();
            cout<<"  ";
            C.Show();
            cout<<"  ";
            D.Show();
        }
        double GetArea(){
            return AB.GetLen()*BC.GetLen();
        }
};

class Triangle: virtual public Shape{
    protected:
        Point A,B,C;
        Line AB,BC,CA;
    public:
        ~Triangle(){
            cout<<"Triangle distructed!"<<endl;
        }
        Triangle(Point &a, Point &b, Point &c):A(a),B(b),C(c),AB(a,b),BC(b,c),CA(c,a){
            cout<<"Triangle constructed!"<<endl;
        }
        void Show(){
            cout<<"Triangle with points:"<<endl<<"  ";
            A.Show();
            cout<<"  ";
            B.Show();
            cout<<"  ";
            C.Show();
        }
        double GetArea(){
            double p = (AB.GetLen()+BC.GetLen()+CA.GetLen())/2;
            return sqrt(p*(p-AB.GetLen())*(p-BC.GetLen())*(p-CA.GetLen()));
        }
};

class Circle: virtual public Shape{
    protected:
        Point cent;
        double radius;
    public:
        ~Circle(){
            cout<<"circle destructed!"<<endl;
        }
        Circle(Point &p, double r):cent(p),radius(r){
            cout<<"circle consturcted!"<<endl;
        }
        void Show(){
            cout<<"Circle at";
            cent.Show();
            cout<<"with radius"<<radius<<endl;
            return;
        }
        double GetArea(){
            return 3.1416*radius*radius;
        }
};
int main(){
    Point A(0,0),B(1,0),C(1,1),D(0,1),E(11,22);
    Line L1(A,B), L2(C,E);
    Rectangle R1(A,B,C,D);
    Triangle T1(B,C,D);
    Circle C1(E,10);
    Shape *ptr[6]={&A,&L1,&L2,&R1,&T1,&C1};
    for(int i =0; i<=5; i++){
        ptr[i]->Show();
        cout<<"with area:"<<ptr[i]->GetArea()<<endl;
    }
}
```
**输出**
```
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Rectangle constructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Point constructed!
Point constructed!
Line constructed!
Triangle constructed!
Point constructed!
circle consturcted!
Point:(0,0)
with area:0
Line from
  Point:(0,0)
to
  Point:(1,0)
with area:0
Line from
  Point:(1,1)
to
  Point:(11,22)
with area:0
Rectangle with points:
  Point:(0,0)
  Point:(1,0)
  Point:(1,1)
  Point:(0,1)
with area:1
Triangle with points:
  Point:(1,0)
  Point:(1,1)
  Point:(0,1)
with area:0.5
Circle atPoint:(11,22)
with radius10
with area:314.16
circle destructed!
Point destructed!
Triangle distructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Rectangle destructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Line destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
Point destructed!
```