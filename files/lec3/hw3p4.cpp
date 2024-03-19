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