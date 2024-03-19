#include<iostream>
using namespace std;
class STUDENT {
    private:
        int num;
        int grade;
    public:
        STUDENT(int n, int g){
            num = n;
            grade = g;
        }
        int get_num(){
            return num;
        }
        int get_grade(){
            return grade;
        }
        void set_num(int n){
            num = n;
        }
        void set_grade(int g){
            grade = g;
        }

};

STUDENT students[5] = {STUDENT(1, 90), STUDENT(2, 80), STUDENT(3, 70), STUDENT(4, 60), STUDENT(5, 50)};
STUDENT *pStudent = students;

int main(){
    for(int i = 0; i<5; i+=2){
        cout<<pStudent->get_num()<<" "<<pStudent->get_grade()<<endl;
        pStudent+=2;
    }
    return 0;
}