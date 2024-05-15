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