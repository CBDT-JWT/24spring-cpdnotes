#include<iostream>
using namespace std;
class B1{
    public:
        B1(int i){
            cout<<"constructing B1 "<<i<<endl;
        }
        ~B1(){
            cout<<"destructing B1"<<endl;
        }
};
class B2{
    public:
        B2(){
            cout<<"constructing B3 *"<<endl;
        }
        ~B2(){
            cout<<"destructing B3"<<endl;
        }
        
};
class C:public B2, virtual public B1{
        int j;
    
    public:
        C(int a, int b, int c):B1(a),memberB1(b),j(c){

        }
    private:
        B1 memberB1;
        B2 memberB2;
};
int main(){
    C obj(1,2,3);
}