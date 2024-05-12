#include<iostream>
using namespace std;
class A{
    int a1;
    protected:
        int a2;
    public:
        int a3;
};
class B:public A{
    int b1;
    protected:
        int b2;
    public:
        int b3;
};
class C:private B{
    int c1;
    protected:
        int c2;
    public:
        int c3;
};
int main(){
    B obb;
    C obc;
    cout<<obb.a1;
    cout<<obb.a2;
    cout<<obb.a3;
    cout<<obc.b1;
    cout<<obc.b2;
    cout<<obc.b3;
    cout<<obc.c3;
    return 0;
}