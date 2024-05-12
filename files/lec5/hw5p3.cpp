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