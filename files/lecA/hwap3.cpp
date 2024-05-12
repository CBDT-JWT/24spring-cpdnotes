#include<iostream>
#include<cstring>
using namespace std;
template<class T, int n>
class Searchable{
    private:
        T a[n];

    public:
        Searchable(T *ptr){
            for(int i=0; i<=n; i++){
                a[i] = ptr[i];
            }
        }
        int search(T tar){
            for(int i =0; i<n; i++){
                if (tar == a[i]){
                    return i;
                }
            }
            return -1;
        }
        void print(){
            cout<<"Searchable with n="<<n<<':'<<endl;
            for(int i =0; i<n; i++){
                cout<<a[i]<<';'<<endl;
            }
        }
};


int main(){
    string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    Searchable<string,10> S1(s);
    S1.print();
    cout<<S1.search("one");
    return 0;
}