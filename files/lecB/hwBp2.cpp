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