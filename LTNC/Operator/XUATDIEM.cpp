#include<iostream>

using namespace std;

struct DIEM
{
   int a, b;
};

istream& operator >> (istream& is, DIEM& p);
ostream& operator << (ostream& os, DIEM p);
bool operator == (DIEM p1, DIEM p2);
bool operator < (DIEM p1, DIEM p2);
DIEM operator + (DIEM p1, DIEM p2);

istream& operator >> (istream& is, DIEM& p){
    is >> p.a >> p.b;
    return is;
}
ostream& operator << (ostream& os, DIEM p){
    os << "(" << p.a <<","<< p.b<<")";
    return os;
}
bool operator == (DIEM p1, DIEM p2){
    return (p1.a==p2.a)&&(p1.b==p2.b);
}
bool operator < (DIEM p1, DIEM p2){
    if (p1.a < p2.a){
        return true;
    }
    else{
        if (p1.a == p2.a){
            if (p1.b < p2.b){
              return true;
            }
        }
    }
    return false;
}
DIEM operator + (DIEM p1, DIEM p2){
    DIEM kq;
    kq.a = p1.a + p2.a;
    kq.b = p1.b + p2.b;
    return kq;
}

struct M1C
{
   DIEM a[100];
    int n;
    DIEM& operator [] (int k){  
        return a[k];
    }
};

istream& operator >> (istream& is, M1C& m){
    m.n = 0;
    while ( cin >> m.a[m.n])
    {
        m.n++;
    }
    return is;
    
}
ostream& operator << (ostream& os, M1C m){
   DIEM max = m[0];
   DIEM d1;
   d1.a = 0;
   d1.b = 0;
   for(int i =0;i<m.n;i++){
       if(max < m[i]){
           max = m[i];
       }
       d1 = d1 + m[i];
   }
   os << max << endl;
   os << d1;

   return os;
}

int main(){
    M1C m;
    cin >> m; 
    cout << m;
    return 0;
}
