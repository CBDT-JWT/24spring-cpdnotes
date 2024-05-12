# 计算机程序设计基础(2)
**作业5**
**江玮陶 清华大学电子工程系**
**2024年3月26日**

---
## 教材p450习题4
### 题目
设计一个用于人事管理的`People`类, 具有的属性如下: 姓名`char name[11]`, 编号`char number[7]`, 性别`char sex[3]`, 生日`birthday`, 身份证号`char id[16]`. 其中出生日期声明为一个类内嵌子对象, 用成员函数实现对人员信息的录入和显示. 要求包括构造函数和析构函数, 拷贝构造函数, 内嵌成员函数, 运算符重载等. 在测试程序中声明.

### 代码
```C++
#include<iostream>
#include<string.h>
using namespace std;
class People{
    public :
    class Date{
            private:
                int year;
                int month;
                int day;
            public:
                Date(int y, int m, int d){
                    year = y;
                    month = m;
                    day = d;
                }
                Date(const Date &d){
                    day= d.day;
                    month = d.month;
                    year = d.year;
                }
                void print(){
                    cout << year << "/" << month << "/" << day << endl;
                }
        };
    private:
        
        char name[11];
        char number[7];
        char sex[3];
        Date birthday;
        char id[16];
    public:
    

        People(char*name, char*number, char*sex, int y, int m, int d, char*id):birthday(y,m,d){
            strcpy(this->name, name);
            strcpy(this->number, number);
            strcpy(this->sex,sex);
            //birthday = new Date(y,m,d);
            strcpy(this->id, id);
        }
        void print(){
            printf("%s,%s,%s,%s",this->name,this->id,this->sex,this->number);
            this->birthday.print();
        }
};
int main(){
    People p1("yx","1234","nv",2024,3,26,"12345678");
    p1.print();
}
```
## 教材p450习题5
### 题目
定义一个`Teacher`类和一个`Student`类. 两者有一部分的数据成员是相同的, 例如：`num`, `name` 和`sex`。编写一个程序 .将一个 `Teacher` 类对象转为 `Student` 类对象，只需将以上3个相同的数据成员移植过去.
### 代码
```C++
#include<iostream>
#include<string.h>
using namespace std;
class Teacher;
class Student{
    private:
        int num;
        char name[10];
        bool sex;
    public:
        Student& operator=(Teacher );
        Student(int num, char*name, bool sex){
            this->num = num;
            this->sex = sex;
            strcpy(this->name, name);
        }
        void print(){
            cout<<"student:"<<name<<num<<sex<<endl;
        }
};
class Teacher{
    private:
        int num;
        char name[10];
        bool sex;
    public:
        friend Student;
        Teacher(int num, char*name, bool sex){
            this->num = num;
            this->sex = sex;
            strcpy(this->name, name);
        }
        void print(){
            cout<<"teacher:"<<name<<num<<sex<<endl;
        }
};
Student& Student::operator= (Teacher t){
    this->num = t.num;
    this->sex = t.sex;
    strcpy(this->name,t.name);
    return *this;
}

int main(){
    Teacher t(123,"asd",1);
    t.print();
    Student s(321,"qwe",0);
    s.print();
    s=t;
    s.print();
}
```
## 选做题1
### 题目
定义一个字符串类`String`，其唯一数据是一个字符串.
- 重载`+`，使其能够完成两端对象的字符串的拼接，并返回一个新的string对象
- 重载`<<`，输出字符串的值
- 重载`*`,对于一个String对象a, `a*3`表示将a中的字符串复制三遍并顺序拼接起来，只对对象a自身进行操作，不要求返回值。
### 代码
```
#include<iostream>
#include<string.h>
using namespace std;
class myString{
    private:
        char* str;
    public:
        myString(char*str){
            int l = strlen(str);
            this->str = new char[l];
            strcpy(this->str,str);
        }
        friend myString operator+ (myString, myString);
        friend ostream& operator<< (ostream &, myString&);
        void operator *(int n){
            int l = strlen(str);
            char*tmp = new char[l*n];
            for(int i = 1; i<= n; i++){
                strcpy(tmp,this->str);
                tmp += l;
            }
            this->str = tmp-l*n;
        }
};
ostream& operator<< ( ostream& output, myString& mstr){
    output<<mstr.str;
    return output;
}
myString operator+ (myString str0, myString str1){
    int l0 = strlen(str0.str);
    int l1 = strlen(str1.str);
    char * tmp = new char[l0+l1];
    strcpy(tmp, str0.str);
    strcpy(tmp+l0,str1.str);
    return myString(tmp);
}
int main()
{
    myString str1("hello!");
    cout<<str1<<endl;
    str1 * 3;
    cout<<str1<<endl;
    myString str2("hahahha!");
    str2 = str1 + str2;
    cout<<str2;
    return 0;
}
```