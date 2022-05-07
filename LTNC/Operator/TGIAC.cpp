#include <iostream>
#include <cmath>

using namespace std;
struct Diem {
    int tung, hoanh;

    bool operator == (Diem X) {
        return (double)tung == X.tung && hoanh == X.hoanh;

    }
  
   
};
    
struct TamGiac {
    Diem dinhA, dinhB, dinhC;
};

//prototype

istream& operator>> (istream& input, Diem& X);
ostream& operator<< (ostream& output, Diem   X);

istream& operator>> (istream& input, TamGiac& T);
ostream& operator<< (ostream& output, TamGiac   T);

double tinhKhoangCach(Diem A, Diem B);

double chuVi(TamGiac T);
double operator+ (TamGiac T1, TamGiac T2);
Diem timTrongTam(TamGiac T);
bool operator < (TamGiac T1, TamGiac T2);
bool operator == (TamGiac T1, TamGiac T2);

int main() {

    TamGiac tg1, tg2;

    cin >> tg1 >> tg2;

    cout << tg1 << endl << tg2 << endl;

    if (tg1 < tg2) 
        cout << "TRUE";
    else 
        cout << "FALSE";

    cout << endl;

    if (tg1 == tg2) 
        cout << "TRUE";
    else 
        cout << "FALSE";

    return 0;
}

//define

double tinhKhoangCach(Diem A, Diem B) {
    return (double)sqrt(pow(B.hoanh - A.hoanh, 2) + pow(B.tung - A.tung, 2));
}

istream& operator>> (istream& input, Diem& X) {
    input >> X.hoanh >> X.tung;
    return input;
}

ostream& operator<< (ostream& output, Diem  X) {
    output << "(" << X.hoanh << "," << X.tung << ")";
    return output;
}

istream& operator >> (istream& input, TamGiac& T) {
    input >> T.dinhA >> T.dinhB >> T.dinhC;
    return input;
}

ostream& operator << (ostream& output, TamGiac   T) {
    output << T.dinhA << T.dinhB << T.dinhC;
    return output;
}

double chuVi(TamGiac T) {
    return tinhKhoangCach(T.dinhA, T.dinhB)
        + tinhKhoangCach(T.dinhB, T.dinhC)
        + tinhKhoangCach(T.dinhA, T.dinhC);
}

double operator+ (TamGiac T1, TamGiac T2) {
    return chuVi(T1) + chuVi(T2);
}

bool operator< (TamGiac T1, TamGiac T2) {
    return chuVi(T1) < chuVi(T2);
}

Diem timTrongTam(TamGiac T) {
    Diem tam;
    tam.hoanh = (T.dinhA.hoanh + T.dinhB.hoanh + T.dinhC.hoanh) / 3;
    tam.tung = (T.dinhA.tung + T.dinhB.tung + T.dinhC.tung) / 3;

    return tam;
}

bool operator== (TamGiac T1, TamGiac T2) {
    return timTrongTam(T1) == timTrongTam(T2);
}