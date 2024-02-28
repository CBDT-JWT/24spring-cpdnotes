#include <iostream>
using namespace std;
const int N = 10;
int get_combination_num(int m,int n){//get C_m^n
    if(n == 1) return m;
    if(m == n) return 1;
    if(n==0) return 1;
    return get_combination_num(m-1,n-1)+get_combination_num(m-1,n);
}
int main(){
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= i; j++){
            cout<<get_combination_num(i,j)<<' ';
        }
        cout<<endl;
    }
    return 0;
}