/*
*编写一个程序，定义一个类 Person，其中包含name(字符指针)和age（整型变量）两个成员变量。
*之后编写Person类的构造函数，复制构造函数和析构函数，在主函数中实现深复制与浅复制，并分析构造函数和析构函数的调用时机
*/
#include <bits/stdc++.h>
using namespace std;
class Person
{
    char *name;
    int age;
    public:
        Person();
        Person(const char*nameIn,int ageIn){
            age = ageIn;
            strcpy (name,nameIn);
        }
        Person(Person &person){
            age = person.age;
            name = new char[strlen(person.name)];
            for(int i = 0; i<strlen(person.name); i++){
                name[i] = person.name[i];
            }
        }
        ~Person();
        void print(){
            cout<<name<<' '<<age<<endl;
        }
};
int main(){
    Person a("alice",18),b=a,c;
    a.print();
    b.print();
    c = a;
    c.print();
    return 0;
}
