# 计算机程序设计基础（2）作业B
**江玮陶**
清华大学电子工程系
## 第一题
```C++
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int N=120;
int main(){
    vector<int> v;
    srand(rand());
    for(int i=0; i<N; i++){
        int tmp = rand()%100;
        v.push_back(tmp);
        cout<<tmp<<' ';
    }
    cout<<endl;
    int a=1,b=0;
    vector<int>::iterator itr =v.begin(); 
    while (itr<v.end()){
        v.erase(itr);
        itr+=a-1;
        a=a+b;
        b=a-b;
    }
    cout<<endl;
    /*sort*/
    sort(v.begin(),v.begin()+v.size()/2,less<int>());
    sort(v.begin()+v.size()/2,v.end(),greater<int>());
    itr = v.begin();
    while(itr<v.end()){
        cout<<*itr<<' ';
        itr++;
    }
    return 0;
}
```
## 第二题
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>A,B,C,D,E;
    /*random init vectors A,B,C*/
    srand(rand());
    for(int i=0;i<12;i++){
        int tmp=rand()%10;
        A.push_back(tmp);
    }

    srand(rand());
    for(int i=0;i<6;i++){
        int tmp=rand()%10;
        B.push_back(tmp);
    }

    srand(rand());
    for(int i=0;i<18;i++){
        int tmp=rand()%10;
        C.push_back(tmp);
    }

    /*get intersections*/
    vector<int>::iterator itr=A.begin();
    while (itr!=A.end()){
        if(find(C.begin(),C.end(),*itr)!=C.end()){
            D.push_back(*itr);
            if(find(B.begin(),B.end(),*itr)!=B.end()){
                E.push_back(*itr);
                
            }
        }
        itr++;
    }
    sort(E.begin(),E.end(),less<int>());
    itr=E.begin();
    while (itr!=E.end())cout<<*itr<<",\n"[++itr==E.end()];
}
```