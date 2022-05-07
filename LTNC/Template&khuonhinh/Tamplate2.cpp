#include <iostream>

using namespace std;

template <typename T>
struct Mang{
	int sl;
	T ptu[100];
	T& operator [] (int i){
		return ptu[i];
	}
};
template <typename T>
istream& operator >> (istream &in, Mang<T> &m);
template <typename T>
ostream& operator << (ostream &out, Mang<T> m);
template <typename T>
T tinhTongPhanTu(Mang<T> m);

struct PhanSo {
	int tu, mau;

	void operator = (int x){
		tu = x;
		mau = 1;
	}
};
int ucln(int a, int b){
	while (b!=0)
	{
		int r = a%b;
		a =b;
		b =r;
	}
	return a;
	
}
istream& operator >> (istream &in, PhanSo &p);
ostream& operator << (ostream &out, PhanSo p);
PhanSo operator + (PhanSo p1, PhanSo p2);
PhanSo rutGon(PhanSo p);

int main() {
	char x;
	cin >> x;
	if (x == 'a'){
		Mang<int> ma;
		cin >> ma;
	
		cout << tinhTongPhanTu<int>(ma);
	}
	else if (x == 'b'){
		Mang<PhanSo> mb;
		cin >> mb;
	
		cout << tinhTongPhanTu<PhanSo>(mb);
	}
	
	return 0;
}
template <typename T>
istream& operator >> (istream &in, Mang<T> &m){
	m.sl = 0;
	while (in >> m[m.sl]){
	m.sl++;
	}
	return in;
}
template <typename T>
ostream& operator << (ostream &out, Mang<T> m){
	for (int i = 0; i < m.sl; i++){
		out << m[i] << " ";
	}
	return out;
}
template <typename T>
T tinhTongPhanTu(Mang<T> m){
	T kq;
	kq = 0;
	for (int i = 0; i < m.sl; i++){
		kq = kq + m[i];
	}
	return kq;
}

istream& operator >> (istream &in, PhanSo &p){
	in >> p.tu >> p.mau;
	return in;
}
ostream& operator << (ostream &out, PhanSo p){
	out << p.tu << "/" << p.mau;
	return out;
}
PhanSo operator + (PhanSo p1, PhanSo p2){
	PhanSo kq;
	kq.tu = p1.tu*p2.mau + p2.tu*p1.mau;
	kq.mau = p1.mau*p2.mau;
	return rutGon(kq);
}
PhanSo rutGon(PhanSo p){
	int x = ucln(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
	return p;
}