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
            cout<<"D::f1"<<endl;
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