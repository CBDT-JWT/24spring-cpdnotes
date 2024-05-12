#include<iostream>
using namespace std;
bool foo(int *a, int *b){
    int a_b;
    bool tmp= (a_b=a-b)||(a==b);
    cout<<"a-b (in ||) = "<<a_b<<endl;;
    return tmp;
}
bool foo1(int*a, int*b){
    int* tmp1 = (int*)(a-b);
    int* tmp2 = (int*)(b==a);
    cout<<"tmp1="<<tmp1<<endl;
    cout<<"tmp2="<<tmp2<<endl;
    return tmp1||tmp2;
}

int main(){
    cout<<foo((int*)1,(int*)0)<<endl;
    cout<<foo1((int*)1,(int*)0)<<endl;
    
    return 0;
}