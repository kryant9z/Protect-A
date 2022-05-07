#include<iostream>

using namespace std;

struct M1C{
    int sl;
    int a[100];

    int& operator [] (int i){
        return a[i];
    }
    void operator = (M1C m){
        sl = m.sl;
        for(int i =0 ;i<sl;i++){
            a[i]=m[i];
        }
    }
};

istream& operator >> (istream& is, M1C& m);
ostream& operator << (ostream& os, M1C m);
M1C operator + (M1C a, M1C b);
bool operator == (M1C a, M1C b);
bool operator != (M1C a, M1C b);

int main(){
M1C f1, f2;
cin >> f1  >> f2;
if(f1==f2){
    cout << "yes";
}
else
cout <<"no";
    return 0;
}

istream& operator >> (istream& is, M1C& m){
    is >>m.sl;
    for(int i =0;i<m.sl;i++){
        is >> m[i];
    }
    return is;
}
ostream& operator << (ostream& os, M1C m){
    for(int i =0;i<m.sl;i++){
        os << m[i];
    }
    return os;
}
M1C operator + (M1C a, M1C b){
    M1C kq;
    if(a.sl >= b.sl){
        kq = a;
        for(int i = 0;i<b.sl;i++){
            kq[i]=kq[i]+b[i];
        }
    }else{
        kq = b;
        for(int i =0 ;i<a.sl;i++){
            kq[i]=kq[i]+a[i];
        }
    }
    return kq;
}
bool operator == (M1C a, M1C b){
    if(a.sl != b.sl){
        return false;
    }
    for(int i =0;i<a.sl;i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
bool operator != (M1C a, M1C b){
    return !(a==b);
}