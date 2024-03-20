#include<iostream>
using namespace std;
class Vector3 {
    private:
        double x;
        double y;
        double z;
    public:
        Vector3(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void print(){
            cout << "(" << x << ", " << y << ", " << z << ")" << endl;
        }
        friend Vector3 operator* (Vector3 &v, Vector3 &w);
};
Vector3 operator* (Vector3 &v, Vector3 &w){
    return Vector3(v.y*w.z-v.z*w.y, v.z*w.x-v.x*w.z, v.x*w.y-v.y*w.x);
}
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    Vector3 v(x,y,z);
    cin>>x>>y>>z;
    Vector3 w(x,y,z);
    Vector3 result = v*w;
    result.print();
    return 0;
}