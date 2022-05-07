#include<iostream>
#include<string>

using namespace std;

struct SV
{
    string name;
    int a, b, c;
};

istream& operator >> (istream& is, SV& p);
ostream& operator << (ostream& os, SV s);
bool operator < (SV p1, SV p2);
double tinhtb(SV p);


int main(){
   SV a[100];
   int n = 0;
   while (cin >> a[n])
   {
       n++;
       cin.ignore();
   }
   SV max = a[0];
   for(int i = 1;i<n;++i){
       if(max < a[i]){
           max = a[i];
       }
   }
    cout << max;
    return 0;
}

istream& operator >> (istream& is, SV& p){
    getline(is, p.name);
    is >> p.a >> p.b >> p.c;
    return is;
}
ostream& operator << (ostream& os, SV s){
    os << s.name ;
    return os;
}
double tinhtb(SV p){
    return (p.a+p.b+p.c)/3;
}

bool operator < (SV p1, SV p2){
    return (tinhtb(p1) < tinhtb(p2));
}
