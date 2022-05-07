#include<iostream>

using namespace std;

struct Phanso{
    int tu, mau;
};

istream& operator >> (istream& is, Phanso& p);
ostream& operator << (ostream& os, Phanso p);
bool operator == (Phanso p1, Phanso p2);
template<typename T>
void xuly();
int main(){
    char x;
    cin >> x;
    if(x=='a'){
         xuly<int>();
    }
    else if (x=='b'){
        xuly<float>();
    }
    else if (x=='c'){
        xuly<Phanso>();
    }
    return 0;
}

istream& operator >> (istream& is, Phanso& p){
    is >> p.tu >> p.mau;
    return is;
}
ostream& operator << (ostream& os, Phanso p){
    os << p.tu << "/" <<p.mau;
    return os;
}
bool operator == (Phanso p1, Phanso p2){
    return p1.tu*p2.mau == p2.tu*p1.mau;
}
template<typename T>
void xuly(){
    T a, b;
    cin >> a >> b;
    if (a==b){
        cout << "true";
    }
    else{
        cout <<"false";
    }
}