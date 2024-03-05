#include<iostream>
using namespace std;
class myclass{
    private:
        int a=10;
    public:
        myclass(int i)
        {
            cout<< "Constructor called"<<endl;
        }
        myclass(){
            cout<< "Default constructor called"<<endl;
        }
        ~myclass()
        {
            cout<< "Destructor called"<<endl;
        }
        int func(myclass &obj)
        {
            cout<< obj.a<<endl;
            return 0;
        }
};

int main()
{
    myclass obj1(1), obj2;
    //obj2.a = 10;
    obj1.func(obj2);
    //cout<<obj1.a;
    return 0;
}