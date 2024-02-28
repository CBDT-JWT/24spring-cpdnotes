#include<iostream>
using namespace std;
void swap0(int *pa,int &b){
    int tmp = b;
    b = *pa;
    *pa = tmp;
    return ;
}
int main(){
    int a = 5,b = 3,*ptr=&a;
    swap0(ptr,b);
    cout<<a<<' '<<b<<endl;
    return 0;
}