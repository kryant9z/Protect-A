#include<iostream>

using namespace std;

struct Bacnhat
{
    int a, b;
};

istream& operator >> (istream& is, Bacnhat& p);
ostream& operator << (ostream& os, Bacnhat p);

int tinhgiatri(Bacnhat p, int x);
Bacnhat operator + (Bacnhat p1, Bacnhat p2);
bool operator == (Bacnhat p1, Bacnhat p2);

int main(){
    Bacnhat f1, f2;
    int x;
    cin >> f1;
    cin >> f2;
    cin >> x;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f1 <<"+"<<f2 << "=" << f1 + f2 << endl;
    cout << tinhgiatri(f1, x)<< endl;
    cout << tinhgiatri(f2, x)<<endl;
    if(f1==f2){
        cout << "TRUE";
    }
    else
    cout << "FALSE";
    return 0;
}
istream& operator >> (istream& is, Bacnhat& p){
    is >> p.a >> p.b;
    return is;
}
ostream& operator << (ostream& os, Bacnhat p){
    os << p.a <<"x+"<<p.b;
    return os;
}

int tinhgiatri(Bacnhat p, int x){
    return (p.a*x+p.b);
}
Bacnhat operator + (Bacnhat p1, Bacnhat p2){
    Bacnhat kq;
    kq.a = p1.a+p2.a;
    kq.b = p1.b+p2.b;
    return kq;
}
bool operator == (Bacnhat p1, Bacnhat p2){
    return (p1.a+p1.b==p2.a+p2.b);
}