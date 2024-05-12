#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
/*make bin file with increasing data*/
void makeIncFile(ofstream &dest,int n){
    int tmp = 0;
    srand(rand());
    for(int i = 0; i<= n; i++){
        tmp+=rand()%10;
        dest.write((char*)&tmp,sizeof(int));
    }
    cout<<"file built with max:"<<tmp<<endl;
    return;
}

int main(){
    ofstream f("f",ios::binary);
    ofstream g("g",ios::binary);
    makeIncFile(f,1000);
    makeIncFile(g,1000);
    f.close();
    g.close();
    ifstream src1("f",ios::binary);
    ifstream src2("g",ios::binary);
    ofstream dest("h",ios::binary);
    int tmp1,tmp2;
    src1.read((char*)&tmp1,sizeof(int));
    src2.read((char*)&tmp2,sizeof(int));
    int cnt =0;
    bool flag1=0,flag2=0;
    while(true){
        if(tmp1>=tmp2){
            dest.write((char*)&tmp2,sizeof(int));
            if(!src2.read((char*)&tmp2,sizeof(int))){
                tmp2 = INF;
                cout<<"2done!"<<endl;
                flag1 = 1;
            }
        }
        else{
            dest.write((char*)&tmp1,sizeof(int));
            if(!src1.read((char*)&tmp1,sizeof(int))){
                tmp1 = INF;
                cout<<"1done!"<<endl;
                flag2=1;
            }
        }
        if(flag1 && flag2) break;
    }
    src1.close();
    src2.close();
    dest.close();
    return 0;
}