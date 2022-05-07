#include<iostream>

using namespace std;

struct SODAO
{
    /* data */int n;
};

istream& operator >> (istream& is, SODAO& p);
ostream& operator << (ostream& os, SODAO p);
bool operator > (SODAO p1, SODAO p2);
int timsodao(SODAO p);
int operator + (SODAO p1, SODAO p2);
int main(){
SODAO f1, f2;
cin >> f1;
cin >> f2;
cout << f1;
cout << f2;
if(f1>f2){
    cout << "YES";
}
else
    cout << "NO";
    cout << endl;
cout << f1+f2;
    return 0;
}
int timsodao(SODAO p){
    int tmp1  = p.n;
    int tmp2 = tmp1;
    int dem = 0;
    int s = 0;
    while(tmp1 > 0){
        tmp1 /= 10;
        dem++;
    }
    for(int i = 0;i<dem;i++){
        s = s*10;
        s += tmp2%10;
        tmp2 /= 10; 
    }
    return s;
}


istream& operator >> (istream& is, SODAO& p){
    is >> p.n;
    return is;
}
ostream& operator << (ostream& os, SODAO p){
    os << "[SoDao] " << p.n << endl;
    return os;
}
bool operator > (SODAO p1, SODAO p2){
    return timsodao(p1) > timsodao(p2);
}
int operator + (SODAO p1, SODAO p2){
    return  timsodao(p1) + timsodao(p2);
    
}

