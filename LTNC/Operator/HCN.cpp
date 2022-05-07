#include<iostream>

using namespace std;

struct rectangular{
    int a, b;
};

istream& operator >> (istream& is, rectangular& p);
ostream& operator << (ostream& os, rectangular p);

bool operator < (rectangular p1, rectangular p2);
int operator + (rectangular p, int x);
int tinhchuvi(rectangular p);

int main(){
    rectangular f1,f2;
    cin >> f1;
    cin >> f2;
    cout << f1 << endl;
    cout << f2 << endl;
    if(f1<f2){
        cout << "true";
    }
    else
    cout <<"false";

    return 0;
}

istream& operator >> (istream& is, rectangular& p)
{
    is >> p.a >> p.b;
    return is;
}
ostream& operator << (ostream& os, rectangular p){
    os << "[HCN]" << p.a <<","<<p.b;
    return os;
}

bool operator < (rectangular p1, rectangular p2){
    return tinhchuvi(p1) < tinhchuvi(p2);
}
int operator + (rectangular p, int x){
    return tinhchuvi(p)+x;
}
int tinhchuvi(rectangular p){
    return (p.a+p.b)*2;
}