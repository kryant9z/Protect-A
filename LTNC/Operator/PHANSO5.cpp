
#include<iostream>
using namespace std;

struct PhanSo
{
    int tu, mau;
    
    PhanSo operator++() //tăng trước
    {
        tu += 1;
        return *this;
    }
    
    PhanSo operator++(int /* phải là int*/) //tăng sau
    {
        PhanSo tmp = *this;
        tu += 1;
        return tmp;
    }
    
        PhanSo operator--() //giảm trước
    {
        tu -= 1;
        return *this;
    }
    
    PhanSo operator--(int ) //giảm sau
    {
        PhanSo tmp = *this;
        tu -= 1;
        return tmp;
    }
};

istream& operator>>(istream& in, PhanSo & p)
{
    in >> p.tu >> p.mau;
    return in;
}
ostream& operator<<(ostream& out, PhanSo p)
{
    out << p.tu << "/" << p.mau;
    return out;
}
int main()
{
    PhanSo ps; 
    cin >> ps;
    char opt;
    cin >> opt >> opt;
    
    switch (opt)
    {
        case '+': cout << ps++ << endl << ps; break;
        case '-': cout << ps-- << endl << ps; break;
    }
    
    return 0;
}
