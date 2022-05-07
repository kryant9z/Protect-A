#include<iostream>
#include<stdio.h>

using namespace std;

struct HCN{
    double a, b;
};
template<typename T>
struct M1C{
    int n;
    T m[100];
};
template<typename T>
void inputArray(M1C<T>&r);
istream& operator >> (istream& is, HCN& p);
ostream& operator << (ostream& os, HCN  p);
template<typename T>
T minNum( M1C<T>r);
bool operator < (HCN m1, HCN m2);
template<typename T>
double sumArray(M1C<T>r);
double operator + (double x, HCN p);
double chuvi( HCN p);
int main(){
    char t;
    cin >> t;
    switch (t) {
        case 'N':
            M1C<int>r1;
            inputArray<int>(r1);
            cout << minNum<int>(r1)<< endl;
            cout << sumArray<int>(r1);
            break;
            
        case 'H':
            M1C<HCN>r2;
            inputArray<HCN>(r2);
            cout << minNum<HCN>(r2)<< endl;
            double s = sumArray<HCN>(r2);
            printf("%.1f", s);
            break;
    }
    return 0;
}

template<typename T>
void inputArray(M1C<T>&r){
    r.n =0;
    while (cin >> r.m[r.n]) {
        r.n++;
    }
}
istream& operator >> (istream& is, HCN& p){
    is >> p.a >> p.b;
    return is;
}
ostream& operator << (ostream& os, HCN  p){
    os << "[HCN] " << p.a <<","<< p.b;
    return os;
}
template<typename T>
T minNum( M1C<T>r){
    T min;
    min = r.m[0];
    for(int i = 1;i<r.n;i++){
        if(r.m[i] < min){
            min = r.m[i];
        }
    }
    return min;
}
bool operator < (HCN p1, HCN p2){
    return chuvi(p1)<chuvi(p2);
}
template<typename T>
double sumArray(M1C<T>r){
    double s = 0;
    for(int i =0;i<r.n;i++){
        s = s+r.m[i];
    }
    return s;
}
double operator + (double x, HCN p){
    return (x+chuvi(p));
}
double chuvi( HCN p){
    return (p.a+p.b)*2;
}
