#include<iostream>
using namespace std;
class Array2d{
    private:
        int rows;
        int cols;
        int** data;
    public:
        Array2d(int r, int c){
            rows = r;
            cols = c;
            data = new int*[rows];
            for(int i = 0; i < rows; i++){
                data[i] = new int[cols];
            }
        }
        ~Array2d(){
            for(int i = 0; i < rows; i++){
                delete[] data[i];
            }
            delete[] data;
        }
        int getVal(int r, int c){
            return data[r][c];
        }
        int setVal(int r, int c, int val){
            data[r][c] = val;
        }
        friend Array2d* operator + (Array2d &Arr1, Array2d &Arr2);
        friend Array2d* operator - (Array2d &Arr1, Array2d &Arr2);
};
Array2d* operator+(Array2d &Arr1, Array2d &Arr2){
    if (Arr1.rows != Arr2.rows || Arr1.cols != Arr2.cols){
        cout << "Error: Dimensions do not match" << endl;
        return NULL;
    }
    Array2d* result = new Array2d(Arr1.rows, Arr1.cols);
    for(int i = 0; i < Arr1.rows; i++){
        for(int j = 0; j < Arr1.cols; j++){
            result->setVal(i,j,Arr1.data[i][j] + Arr2.data[i][j]);
        }
    }
    return result;
}
Array2d* operator -(Array2d &Arr1, Array2d &Arr2){
    if (Arr1.rows != Arr2.rows || Arr1.cols != Arr2.cols){
        cout << "Error: Dimensions do not match" << endl;
        return NULL;
    }
    Array2d* result = new Array2d(Arr1.rows, Arr1.cols);
    for(int i = 0; i < Arr1.rows; i++){
        for(int j = 0; j < Arr1.cols; j++){
            result->setVal(i,j,Arr1.data[i][j] - Arr2.data[i][j]);
        }
    }
    return result;
}
int main(){
    int r,c;
    cout<<"please enter the number of rows and columns for arrays: ";
    cin>>r>>c;
    Array2d A(r,c);
    Array2d B(r,c);
    cout<<"please enter the elements of the first array: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            A.setVal(i,j,x);
        }
    }
    cout<<"please enter the elements of the second array: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            B.setVal(i,j,x);
        }
    }
    Array2d* C = A + B;
    if(C != NULL){
        cout<<"The sum of the two arrays is: "<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<C->getVal(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    Array2d* D = A - B;
    if(D != NULL){
        cout<<"The difference of the two arrays is: "<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<D->getVal(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}