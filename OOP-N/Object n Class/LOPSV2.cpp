#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Diem{
    float n;
    float a[100];

    public:

    float& operator [] (int i ){
        return a[i];
    }
    void operator = (Diem m){
        n = m.n;
        for(int i =0;i<n;i++){
            a[i]=m[i];
        }
    }
    friend istream& operator >> (istream& is, Diem& p){
       p.n =0;
       while (is >> p[p.n])
       {
           /* code */p.n++;
       }
       return is;
    }
    friend ostream& operator << (ostream& os, Diem p){
        for(int i =0;i<p.n;i++){
            os << p[i] <<" ";
        }
        return os;
    }
    // Diem operator = (Diem a){
    //     return Diem(a);
    // }
    float DTB(){
        float S =0;
        for(int i =0;i<n;i++){
            S = S + a[i];
        }
        S = S/n;
        return S;
    }

};

class SinhVien{
    string name;
    string mssv;
    Diem diemhs;
    public:
    friend istream& operator >> (istream& is, SinhVien& s){
        getline(is, s.name);
        is >> s.mssv;
        is >> s.diemhs;
        return is;
    }

    friend ostream& operator << (ostream& os, SinhVien s){
        os << "Ho Ten: " << s.name << endl;
        os << "Ma Sinh Vien: " << s.mssv << endl;
        os << "DTB: " << setprecision(1) << fixed << s.getTB();
    }
    
    float getTB(){
        return diemhs.DTB();
    }
    bool operator < (SinhVien s){
        return getTB() < s.getTB();
    }
};
int main(){
    SinhVien x;
    cin >> x;
    cout << x << endl;
    return 0;
}