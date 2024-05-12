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