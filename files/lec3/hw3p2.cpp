#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
class STUDENT{
    private:
        int num;
        int grade;
        char* name;
    public:
        STUDENT (int n, int g, char* nm){
            set_num(n);
            set_grade(g);
            set_name(nm);
        }
        STUDENT(const STUDENT& s) {
            num = s.num;
            grade = s.grade;
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }
        int get_num(){
            return num;
        }
        int get_grade(){
            return grade;
        }
        char* get_name(){
            return name;
        }
        void set_num(int n){
            num = n;
        }
        void set_grade(int g){
            grade = g;
        }
        void set_name(char* n){
            name = n;
        }
};

STUDENT* get_Max(STUDENT* pBegin, int n){
    int maxGrade = -INF;
    STUDENT* pmax_student = pBegin;
    for(int i = 0; i<n; i++){
        if(pBegin[i].get_grade()>maxGrade){
            maxGrade = pBegin[i].get_grade();
            pmax_student = pBegin+i;
        }
    }
    return pmax_student;
}

int main(){
    STUDENT students[10] ={STUDENT(2024010001,90,"Alice"),STUDENT(2024010002,80,"Bob"),STUDENT(2024010003,70,"Cindy"),STUDENT(2024010004,60,"David"),STUDENT(2024010005,50,"Eva"),STUDENT(2024010006,40,"Frank"),STUDENT(2024010007,30,"Grace"),STUDENT(2024010008,20,"Helen"),STUDENT(2024010009,10,"Ivy"),STUDENT(2024010010,0,"Jack")};
    STUDENT* pStudent = students;
    STUDENT* pmax_student = get_Max(pStudent, 5);
    cout<<pmax_student->get_num()<<" "<<pmax_student->get_grade()<<" "<<pmax_student->get_name()<<endl;
    return 0;
}