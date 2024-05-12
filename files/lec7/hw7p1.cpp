#include<iostream>
#include<string.h>
using namespace std;
class People{
    public:
        class Date{
            public:
                int year;
                int month;
                int day;
                Date(int y=0,int m=0, int d=0):year(y),month(m),day(d){
                    cout<<"date"<<*this<<"constructed!"<<endl;
                    }
                Date(Date &d)
                {
                    month = d.month;
                    year = d.year;
                    day = d.day;
                    cout<<"date"<<*this<<"constructed!"<<endl;
                }
                ~Date(){
                    cout<<"date"<<*this<<"distructed!"<<endl;
                }
                friend ostream& operator<<(ostream&, Date &);
        };
        People(){cout<<"people default constructed"<<endl;}
        People(char*name, char*number, char*sex, int y,int m, int d, char*id){
            strcpy(this->name,name);
            strcpy(this->number,number);
            strcpy(this->sex,sex);
            strcpy(this->id,id);
            this->birthday=Date(y,m,d);
            cout<<this->name<<"constructed!"<<endl;
        }
        People(People &p){
            strcpy(this->name,p.name);
            strcpy(this->number,p.number);
            strcpy(this->sex,p.sex);
            strcpy(this->id,p.id);
            this->birthday = p.birthday;
            cout<<this->name<<"constructed!"<<endl;
        }
        ~People(){
            cout<<name<<"distructed!"<<endl;
        }
        void print(){
            cout<<name<<' '<<number<<' '<<sex<<' '<<birthday<<' '<<id<<endl;
        }
    private:
        char name[11];
        char number[7];
        char sex[3];
        Date birthday;
        char id[16];

};
ostream &operator<<(ostream &output, People::Date&d){
    output<<'['<<d.year<<'/'<<d.month<<'/'<<d.day<<']';
    return output;
}
int main(){
    People *A= new People[3];
    People B1 ("alice","114514","nv",2024,4,9,"1919810");
    A[0]=B1;
    People B2("bob","12345","nan",2023,3,6,"1234567");
    A[1]=B2;
    A[2]=A[0];
    for(int i=0;i<=2;i++ ){
        A[i].print();
    }
    return 0;
}