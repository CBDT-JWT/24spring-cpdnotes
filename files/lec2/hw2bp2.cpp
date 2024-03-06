/********************************************************
 * 利用类（class）实现链表（见课本p.297 11.4节），要求实现链表
 * 元素查找、插入、删除、逆转、打印，并自行编写测试样例，将代码
 * 和输出结果放入文档中
*********************************************************/
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
