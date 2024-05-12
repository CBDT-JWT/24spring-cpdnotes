#include<stdio.h>
int foo(int*a,int*b){
    return (a-b)||(a==b); 
}
int main(){
    char* a="123";
    printf("%d\n",foo(a,a+1));
    return 0;
}