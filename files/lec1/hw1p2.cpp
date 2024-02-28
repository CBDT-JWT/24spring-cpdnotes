#include<iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    double ***pppArray = new double**[n];
    for(int i = 0; i< n; i++){
        pppArray[i]=new double*[n];
        for(int j = 0; j< n; j++){
            pppArray[i][j]=new double[n];
            for(int k=0;k<n;k++){
                pppArray[i][j][k]=i*j/(k+1);
            }
        }
    }
    double sum = 0;
    for(int i =0;i<n;i++){
        for(int j = 0; j<n;j++){
            for(int k =0; k<n; k++)sum+=pppArray[i][j][k];
        }
    }
    cout<<sum;
    return 0;
}