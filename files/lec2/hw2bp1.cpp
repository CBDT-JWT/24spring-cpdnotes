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

