#include<iostream>

using namespace std;

struct SoMoi{
int n;

};
istream& operator >> (istream& is, SoMoi& p );
ostream& operator << (ostream& os, SoMoi p );
bool operator > (SoMoi p1, SoMoi p2);
SoMoi operator + (SoMoi p1, SoMoi p2);
int tinhsomoi(SoMoi p1, SoMoi p2);

int main(){
SoMoi f1, f2;
cin >> f1;
cin >> f2;
cout << f1;
cout << f2;
if(f1 > f2){
    cout << "true";
}
else
cout << "false" << endl;
cout << f1+ f2;

    return 0;
}

istream& operator >> (istream& is, SoMoi& p ){
    is >> p.n;
    return is;
}
ostream& operator << (ostream& os, SoMoi p ){
    os << "[SoMoi] " << p.n << endl;
    return os;
}
int tinhsomoi(SoMoi p){
    int s = 0;
    while (p.n>0)
    {
        /* code */int x  = p.n%10;
        s = s + x;
        p.n /= 10;
    }
    return s;
    
}
bool operator > (SoMoi p1, SoMoi p2){
    return tinhsomoi(p1) > tinhsomoi(p2);
}
SoMoi operator + (SoMoi p1, SoMoi p2){
    SoMoi kq;
    kq.n =  tinhsomoi(p1)+tinhsomoi(p2);
    return kq;
}
