#include<iostream>
using namespace std;

class ARRINT1{
    private:
        int n,b,a[100];
    public:
        ARRINT1();
        ~ARRINT1();
        int getMod();
        ARRINT1 getOddNumber(); 
        friend istream& operator >> (istream& in,ARRINT1 &d);
        friend ostream& operator << (ostream& out,ARRINT1 d);
        int operator [](int i){
            return a[i];
        }
};
ARRINT1::ARRINT1(){}
ARRINT1::~ARRINT1(){}
istream& operator >> (istream& in,ARRINT1 &d){
    in >> d.n >> d.b;
    for(int i = d.n - 1;i >= 0;i--){
        in >> d.a[i];
    }
    return in;
}
ostream& operator << (ostream& out,ARRINT1 d){
    out << d.getMod() << endl;
    d.getOddNumber();
    return out;
}
int ARRINT1::getMod(){
    int kq = 0;
    for(int i = 0;i < n;i++){
        kq +=a[i]%b;
    }
    return kq;
}
ARRINT1 ARRINT1::getOddNumber(){
    ARRINT1 t;
    t.n = 0;
    for(int i = 0;i < n;i++){
        if(a[i]%2 != 0){
            t.a[t.n] = a[i];
            t.n++;
        }
    }
    cout << t.n << ":";
    for(int i = 0;i < t.n;i++){
        cout << t.a[i];
    }
}
int main(){
    ARRINT1 a;
    cin >> a;
    cout << a;
    
    return 0;
}