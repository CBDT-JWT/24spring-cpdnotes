#include<iostream>
#pragma pack(1)
using namespace std;

struct s1{
    char a;
    int b;
};
struct s2{
    int a;
    char b;
};
union u{
    s1 A1;
    s2 A2;
};
template <typename T>
bool foo(T a,T b){
    cout<<"a-b  = "<<a-b<<endl;
    cout<<"a==b = "<<(a==b)<<endl;
    cout<<((a-b)||(a==b))<<endl;
    return (a-b)||(a==b);
}

int main(){
    cout<<foo((int*)1,(int*)0)<<endl;
    u uni;
    int* ptr1=&(uni.A1.b);
    int* ptr2=&(uni.A2.a);
    cout<<foo(ptr1,ptr2)<<endl;
    cout<<(((int*)1-(int*)0)||(int*)1==(int*)0)<<endl;
    return 0;
}
