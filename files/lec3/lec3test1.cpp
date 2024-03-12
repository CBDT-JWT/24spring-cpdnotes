#include<iostream>
using namespace std;
class myclass{
    private:
        int num;
    public:
        static int cnt;
        myclass(int n){
            num = n;
            cnt++;
        }
        int* getnum (){
            return &num;
        } 
};
int myclass::cnt = 0;
int main(){  
    myclass obj(5);
    myclass A(10), B(20);
    cout<<myclass::cnt<<endl;
    return 0;
}