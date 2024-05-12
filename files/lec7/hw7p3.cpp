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