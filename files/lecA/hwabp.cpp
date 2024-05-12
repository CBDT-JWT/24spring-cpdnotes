#include<iostream>
using namespace std;
template <typename T>
void sort(T* ptr, int size, bool (*cmp)(T a, T b)){
    if (size == 2){
       if ((*cmp)(ptr[0],ptr[1])){
                T tmp = ptr[0];
                ptr[0] = ptr[1];
                ptr[1] = tmp;
            } 
        return;
    }
    if (size <= 1) return;
    sort (ptr,size/2,*cmp);
    sort (ptr+size/2,size-size/2,*cmp);

    //merge
    T* dest = new T[size];
    int l=0,r=size/2,cnt=-1;
    while(1){
        cnt++;
        if(l==size/2&&r==size)break;
        if (l==size/2){
            dest[cnt]=ptr[r];
            r++;
            continue;
        }
        if(r==size){
            dest[cnt]=ptr[l];
            l++;
            continue;
        }
        if((*cmp)(ptr[l],ptr[r])){
            dest[cnt]=ptr[r];
            r++;
            continue;
        }
        dest[cnt]=ptr[l];
        l++;
        continue;
    }
    for(int i=0;i<size;i++){
        ptr[i]=dest[i];
        
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