#include<iostream>
using namespace std;
class Mammal{
    public:
        virtual void speak()=0;
};
class Dog: public Mammal{
    public:
    void speak(){
        cout<<"dog::speak() called!"<<endl;
    }
};
int main(){
    Dog Siqi;
    Siqi.speak();
    return 0;
}