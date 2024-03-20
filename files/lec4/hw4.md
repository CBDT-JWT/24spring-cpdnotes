# 计算机程序设计基础（2） 作业-4
**江玮陶    清华大学电子工程系**
## 2
>分析复制构造函数与类型转换构造函数的区别与联系?总结一下到目前为止学习了哪些类型的构造函数?各有什么特点?

**区别**:
- 复制构造函数用于创建一个新对象作为现有对象的副本,而类型转换构造函数用于从另一种类型的对象转换.
- 复制构造函数参数是对同一类型的对象的引用,而类型转换构造函数的参数是要转换的类型.
**联系**:
- 二者都是构造函数,都可以用于创建新的对象.
- 二者都可以被隐式调用.

目前为止学习了构造函数,拷贝构造函数和类型转换构造函数.

## 6
>编写一个程序,用成员函数重载运算符`+`和`-`将两个二维数组相加相减,要求二维数据的大小和值由键盘输入。

**Solution**
```C++
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
        Array2d* operator+(Array2d &Arr){
            if (rows != Arr.rows || cols != Arr.cols){
                cout << "Error: Dimensions do not match" << endl;
                return NULL;
            }
            Array2d* result = new Array2d(rows, cols);
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result->setVal(i,j,data[i][j] + Arr.getVal(i,j));
                }
            }
            return result;
        }
        Array2d* operator -(Array2d &Arr){
            if (rows != Arr.rows || cols != Arr.cols){
                cout << "Error: Dimensions do not match" << endl;
                return NULL;
            }
            Array2d* result = new Array2d(rows, cols);
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result->setVal(i,j,data[i][j] - Arr.getVal(i,j));
                }
            }
            return result;

        }
};
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
```
## 7
>修改第6题程序,用友元函数重载运算符`+ `和`-`将两个二维数组相加和相减，要求两个二维数据的值都由键盘输入。

```C++
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
```
### 选做题1
> 编写一个三维向量类vector3，重载运算符`*`，实现两个向量间的外积，重载为友元函数.

**Solution**
```C++
#include<iostream>
using namespace std;
class Vector3 {
    private:
        double x;
        double y;
        double z;
    public:
        Vector3(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void print(){
            cout << "(" << x << ", " << y << ", " << z << ")" << endl;
        }
        friend Vector3 operator* (Vector3 &v, Vector3 &w);
};
Vector3 operator* (Vector3 &v, Vector3 &w){
    return Vector3(v.y*w.z-v.z*w.y, v.z*w.x-v.x*w.z, v.x*w.y-v.y*w.x);
}
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    Vector3 v(x,y,z);
    cin>>x>>y>>z;
    Vector3 w(x,y,z);
    Vector3 result = v*w;
    result.print();
    return 0;
}
```
### 选做题2
> 编写`Date`类，包含年、月、日，并重载`++`运算符（前置后置都需要重载），实现日期增加1天，重载为成员函数

**Solution**
```C++
#include<iostream>
using namespace std;
class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void print(){
            cout << day << "/" << month << "/" << year << endl;
        }
        void operator++ ();
        void operator++ (int);
};

void Date:: operator ++ (){
    if(day == 28&&month == 2&&(year%4!=0 || (year%100==0 && year%400!=0))){
        day = 1;
        month = 3;
    }
    else if(day == 29&&month == 2){
        day = 1;
        month = 3;
    }
    else if(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        day = 1;
        month++;
    }
    else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
        day = 1;
        month++;
    }
    else if(day == 31 && month == 12){
        day = 1;
        month = 1;
        year++;
    }
    else{
        day++;
    }
    return;
}
void Date::operator++ (int){
    if(day == 28&&month == 2&&(year%4!=0 || (year%100==0 && year%400!=0))){
        day = 1;
        month = 3;
    }
    else if(day == 29&&month == 2){
        day = 1;
        month = 3;
    }
    else if(day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        day = 1;
        month++;
    }
    else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
        day = 1;
        month++;
    }
    else if(day == 31 && month == 12){
        day = 1;
        month = 1;
        year++;
    }
    else{
        day++;
    }
    return;
}
int main(){
    Date date(1,1,1900);
    date++;
    date.print();
    ++date;
    date.print();
    return 0;
}
```
