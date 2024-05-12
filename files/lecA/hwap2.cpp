#include<iostream>
using namespace std;
template <typename T>
void sort(T* ptr, int size, bool (*cmp)(T a, T b)){
    for(int i = 0; i<size-1; i++)
        for (int j = i+1; j<size;j++ ){
            if ((*cmp)(ptr[i],ptr[j])){
                T tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
        }
    return;
}

bool intGreater (int a,int b){
    return a>b;
}

bool doubleLess (double a, double b){
    return a<b;
}
int main(){
    int a[10]={1,4,3,6,3,2,2,1,4,5};
    sort(a,10,intGreater);
    for(int i = 0; i<10; i++ ){
        cout<<a[i]<<' ';
    }
    double b[10]={1.1,3.3,2.2,5.7,4.5,2.3,9.8,44.5,2.5,3.0};
    sort(b,10,doubleLess);
    cout<<endl;
    for(int i = 0; i<10; i++ ){
        cout<<b[i]<<' ';
    }
    return 0;
}