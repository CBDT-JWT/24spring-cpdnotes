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