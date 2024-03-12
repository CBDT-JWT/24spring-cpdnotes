# 程序设计基础(2)作业2
*江玮陶 清华大学电子工程系*

---

## 练习题2
什么是类的构造函数？其主要用途是什么？本章学习了哪些构造函数类型？它们各有什么特点？

**Soulution**

类的构造函数在对象被构造的时候调用，一般用来进行对象的初始化工作。本章中学习了构造函数和复制构造函数。前者的参数为空或为某些参数，通过`对象名(参数)`调用;后者的参数为同类对象的引用,用来用已有的对象初始化新的对象,在对象被复制的时候调用.
## 练习题3

复制构造函数在什么时候会被自动调用?在哪些情况下会产生所谓的"浅拷贝"问题?

**Soulution**

复制构造函数在
1. 用对象赋初值
1. 往函数里传对象作为形参
1. 函数返回了对象

时调用.当被复制的对象中有指针等时,会出现拷贝了被复制对象的对应地址而没有拷贝相应的值造成浅拷贝问题.
## 练习题10

**（1）** 

输出为
```
Constructor Called! Address = 0x0x61fdec
Copy Constructor Called! Address = 0x0x61fe04
Copy Constructor Called! Address = 0x0x61fdf8
Destructor Called! Address = 0x0x61fdf8
Destructor Called! Address = 0x0x61fe04
Destructor Called! Address = 0x0x61fdec
```
调用构造函数一次,在构造`Date today`时调用;调用复制构造函数两次,在传递today进入`func()`时和传出Date(A)时候调用;调用析构函数三次,顺序为上述构造函数调用顺序的逆序.


**（2）**

1. 输出为
    ```
    Constructor Called! Address = 0x0x61fdf8
    Copy Constructor Called! Address = 0x0x61fe04
    Destructor Called! Address = 0x0x61fe04
    Destructor Called! Address = 0x0x61fdf8
    ```

    一共调用构造函数1次(`Date today;`),复制构造函数1次(`Date B (A);`),析构函数两次,先调用B的析构函数(因为在`func`函数内),再调用today的析构函数.
1. 输出为
    ```
    Constructor Called! Address = 0x0x61fdf8
    Copy Constructor Called! Address = 0x0x61fe04
    Copy Constructor Called! Address = 0x0x61fda4
    Destructor Called! Address = 0x0x61fda4
    ```
    
    同时编译器在`today = func(today);`语句处提示`segmentation fault`错误.

    一共调用构造函数1次(`Date today;`),复制构造函数2次(`Date B (A);`和`return B;`),析构函数一次,推测在析构B(A)的时候发生`segmentation fault`错误.
1. 输出为
    ```
    Constructor Called! Address = 0x0x61fdec
    Copy Constructor Called! Address = 0x0x61fe04
    Copy Constructor Called! Address = 0x0x61fdf8
    Destructor Called! Address = 0x0x61fdf8
    Destructor Called! Address = 0x0x61fe04
    Destructor Called! Address = 0x0x61fdec
    ```
    一共调用构造函数1次(`Date today;`),复制构造函数2次(A作为形参传入函数和A作为返回值传出函数),析构函数3次,依次析构返回值,形参和today.

## 选作1
编写一个程序，定义一个类 Person，其中包含name(字符指针)和age（整型变量）两个成员变量。之后编写Person类的构造函数，复制构造函数和析构函数，在主函数中实现深复制与浅复制，并分析构造函数和析构函数的调用时机

**Soulution**

```C++
#include <bits/stdc++.h>
using namespace std;
class Person
{
    char *name;
    int age;
    public:
        Person(const char*nameIn,int ageIn){
            age = ageIn;
            strcpy (name,nameIn);
        };
        Person (){
            cout<<"test"<<endl;
        }
        Person(Person &person){
            age = person.age;
            name = new char[strlen(person.name)];
            for(int i = 0; i<strlen(person.name); i++){
                name[i] = person.name[i];
            }
            name[strlen(person.name)]='\0';
        };
        void print(){
            cout<<name<<' '<<age<<endl;
        }
        void changeName(char* newName){
            strcpy(name,newName);
        }
};

int main(){
    Person a("alice",18),b=a;
    a.print();
    b.print();
    Person c;
    c = a;
    c.print();
    a.changeName("bob");
    a.print();
    b.print();
    c.print();
    return 0;
}
```
**Output**
```
alice 18
alice 18
test
alice 18
bob 18
alice 18
bob 18
```
## 选作2
利用类（class）实现链表（见课本p.297 11.4节），要求实现链表元素查找、插入、删除、逆转、打印，并自行编写测试样例，将代码和输出结果放入文档中

**Soulution**

```C++
#include<iostream>
#include<string.h>
using namespace std;
class Node{
    private:
        int key;
        char* value;
        Node* pNextNode;
    public:
        Node(){
            key = 0;
            value = NULL;
            pNextNode = NULL;
        }
        Node(int Newkey, const char* Newvalue){
            key = Newkey;
            value = new char[strlen(Newvalue)+1];
            pNextNode = NULL;
            strcpy(value,Newvalue);
        }
        ~Node(){
            delete value;
            //delete pNextNode;
        }
        int insertNode(int destPrevKey,int newKey,const char* newValue){
            if (key == destPrevKey){
                pNextNode = new Node;
                pNextNode -> key = newKey;
                strcpy(pNextNode -> value,newValue);       
            }
            else pNextNode&&(pNextNode->insertNode(destPrevKey,newKey,newValue));
            return 0;
        }
        Node* search(const char* targetValue){
            if(strcmp(value,targetValue)==0)return this;
            else if (pNextNode!=NULL) return (pNextNode->search(targetValue));
            else {
                cout<<"value "<<targetValue<<"not found!"<<endl;
                return NULL;
            }
        }
        int printChain(){
            cout<<key<<':'<<value<<endl;
            return pNextNode&&(pNextNode->printChain());
        }
        int appendNode(int newKey, const char* newValue){
            if(pNextNode == NULL){
                pNextNode = new Node;
                pNextNode -> key = newKey;
                pNextNode->value = new char[strlen(newValue)+1];
                strcpy(pNextNode -> value , newValue);
                pNextNode -> pNextNode = NULL;
                return 0;
            }
            else return pNextNode->appendNode(newKey, newValue);
        }
        int deleteNextNode(){
            if(pNextNode == NULL) return -1;
            Node* pTmpNode = pNextNode;
            pNextNode = pNextNode->pNextNode;
            delete pTmpNode;
            return 0;
        }
        Node* reverseFrom(){
            if(pNextNode == NULL ) return this;
            Node* pTmp = pNextNode;
            Node* ret = pNextNode->reverseFrom();
            pNextNode->pNextNode = this;
            pNextNode = NULL;
            return ret;
        }
        int getkey(){
            return key;
        }
};
int main(){
    Node* HEAD = new Node(1,"alice");
    HEAD->appendNode(2,"bob");
    HEAD->appendNode(3,"Carol");
    HEAD->appendNode(4,"Dave");
    HEAD->appendNode(5,"Eric");
    HEAD->appendNode(6,"Fred");
    HEAD->printChain();
    cout<<"-----------------------------------"<<endl;
    HEAD->deleteNextNode();
    HEAD->printChain();
    cout<<"-----------------------------------"<<endl;
    cout<<HEAD->search("Eric")->getkey()<<endl;
    cout<<"-----------------------------------"<<endl;
    HEAD = HEAD->reverseFrom();
    HEAD->printChain();
    cout<<"-----------------------------------"<<endl;
    HEAD->appendNode(7,"George");
    HEAD->search("Eric")->deleteNextNode();
    HEAD->printChain();
    return 0;
}
```
**Output**
```
1:alice
2:bob
3:Carol
4:Dave
5:Eric
6:Fred
-----------------------------------
1:alice
3:Carol
4:Dave
5:Eric
6:Fred
-----------------------------------
5
-----------------------------------
6:Fred
5:Eric
4:Dave
3:Carol
1:alice
-----------------------------------
6:Fred
5:Eric
3:Carol
1:alice
7:George
```