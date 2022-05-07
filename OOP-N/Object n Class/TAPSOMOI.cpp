#include<iostream>

using namespace std;

class TSM {
    int x, z, y, t;
    public:
    int setX();
    int setY();
    int setZ();
    int setT();
    void getX(int k);
    void getY(int k);
    void getZ(int k);
    void getT(int k);
     TSM (int _x  = 0, int _y =0, int _z =0, int _t = 0){
         x = _x;
         y = _y;
         z = _z;
         t = _t;
     }
    TSM(const TSM& p){
        x = p.x;
        y = p.y;
        z = p.z;
        t = p.t;
    }
    ~TSM(){}
    friend istream& operator >> (istream& is, TSM& p){
        is >> p.x >> p. y >> p.z >> p.t;
        return is;
    }
    friend ostream& operator << (ostream& os, TSM p){
        os << "[TapSoMoi] " << p.x <<";" <<p.y <<";" << p.z <<";" << p.t << endl;
        return os;
    }
    TSM operator +(TSM a){
        TSM kq;
        kq.x = x+a.x;
        kq.y = y+a.y;
        kq.z = z+a.z;
        kq.t = t+a.t;
        return kq;
    }
    bool operator < (TSM a){
        return (x+y+z+t) < (a.x+a.y+a.t+a.z);
    }
    void operator = (TSM k){
     x = k.x;
     y = k.y;
     z = k.z;
     t = k.t;
    }
    TSM operator ++ (){
       x++;
       t++;
        return TSM(x,y,z,t);
    }

};
int main(){
    TSM f1, f2;
    cin >> f1;
    cin >> f2;
    cout << f1;
    cout << f2;
    if(f1<f2)
    {
        cout <<"true";
    }
    else{
        cout << "false";
    }
    cout << f1+f2;
    ++f1;
    cout << f1;
    return 0;
}