#include<bits/stdc++.h>
#include<string.h>
using namespace std;
char buf[40];
int main(){
    ofstream tfile("data.dat");
    if(!tfile){
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while(true){
        cin.getline(buf,30,'\n');
        if(strlen(buf)==0) break;
        tfile<<buf<<endl;
    }
    tfile.close();
    ifstream srcFile("data.dat");
    while(true){
        memset(buf,0,sizeof(buf));
        srcFile.getline(buf,30,'\n');
        if(strlen(buf)==0) break;
        cout<<buf<<endl;
    }
    return 0;
}