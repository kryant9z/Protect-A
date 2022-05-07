#include<iostream>

using namespace std;

struct Bacnhat2{
    int a, b;
};
istream& operator >> (istream& is, Bacnhat2& p);
ostream& operator << (ostream& os, Bacnhat2 p);

int tinhgiatri(Bacnhat2 p, int x);
bool operator == (Bacnhat2 p1, Bacnhat2 p2);
Bacnhat2 operator + (Bacnhat2 p1, Bacnhat2 p2);

int main(){
Bacnhat2 f1, f2;
int x;
cin >> f1;
cin >> f2;
cin >> x;
cout << f1 << endl;
cout << f2 << endl;
cout << f1 <<"+"<<f2<<"="<<f1+f2<< endl;
cout << tinhgiatri( f1, x) << endl;
cout << tinhgiatri( f2, x) << endl;
if(f1==f2){
    cout <<"TRUE";
}
else
cout <<"FALSE";
    return 0;
}
istream& operator >> (istream& is, Bacnhat2& p){
    is >> p.a >> p.b;
    return is;
}
ostream& operator << (ostream& os, Bacnhat2 p){
    os << p.a <<"x+"<<p.b;
    return os;
}

int tinhgiatri(Bacnhat2 p, int x){
    return p.a*x+p.b;
}
bool operator == (Bacnhat2 p1, Bacnhat2 p2)
{
    return (p1.a+p1.b == p2.a+p2.b);
}
Bacnhat2 operator + (Bacnhat2 p1, Bacnhat2 p2){
    Bacnhat2 kq;
    kq.a = p1.a +p2.a;
    kq.b = p1.b+p2.b;
    return kq;
}