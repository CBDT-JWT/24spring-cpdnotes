# 程设作业1

*江玮陶 清华大学电子工程系*

## P1

用C++打印杨辉三角，直至第十行，格式为
 
1
 
1  2  1
 
1   3   3   1
 
……

**Soulution**

```C++
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
```

## P2

用C＋＋编程实现如下三维动态数组x：动态数组大小为n×n×n，x[i][j][k] = i*j/(k+1)，输出该三维数组各个元素之和，取n=5,10,15

**Soulution**

```C++
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
```

# 选做题：
 
## P1
编写一个 C++ 程序，实现一个函数 swap0()，该函数接受两个参数，一个是整型指针，一个是整型引用。函数的功能是将整型指针指向的值与整型引用的值进行交换。

**Soulution**
```C++
void swap0(int *pa,int &b){
    int tmp = b;
    b = *pa;
    *pa = tmp;
    return ;
}
```

## P2
利用‘*’符号，使用格式控制符，在控制台组成一个“龙”字图样（不需要过于精确）

**Solution**
```C++
#include<iostream>
using namespace std;
int main(){
cout<<"    *"<<endl<<"    *    *"<<endl<<"**********"<<endl<<"   *    *"<<endl<<"  *  **"<<endl<<" *  ***    *"<<endl<<"*  *  ******"<<endl;
    return 0;
}
```