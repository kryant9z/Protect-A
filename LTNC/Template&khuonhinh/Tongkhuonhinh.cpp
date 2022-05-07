#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo {
	int tu, mau;
	void operator = (int x) {
		tu = x;
		mau = 1;
	}
};
template <typename type>
struct Mang {
	int n;
	type a[100];
	type& operator [] (int i) {
		return a[i];
	}
};

istream& operator >> (istream& in, PhanSo& p);
ostream& operator << (ostream& out, PhanSo p);
PhanSo operator + (PhanSo p1, PhanSo p2);
PhanSo rutGon(PhanSo p);
template <typename type>
istream& operator >> (istream& in, Mang <type>& m);
template <typename type>
type tinhTongMang(Mang <type> m);
template <typename type>
void result(Mang <type> m);
int ucln(int a, int b);

int main() {

	char t;
	Mang <int> m1;
	m1.n = 0;
	Mang <PhanSo> m2;
	m2.n = 0;
	while (cin >> t) {
		if (t == 'a') {
			cin >> m1;
		}
		else {
			cin >> m2;
		}
	}
	result <int>(m1);
	result <PhanSo>(m2);

	return 0;
}

int ucln(int a, int b){
	while (b!=0)
	{
		/* code */int x = a%b;
		a = b;
		b = x;
	}
	return a;
	
}
istream& operator >> (istream& in, PhanSo& p) {
	in >> p.tu >> p.mau;
	return in;
}
ostream& operator << (ostream& out, PhanSo p) {
	out << p.tu << "/" << p.mau;
	return out;
}
PhanSo operator + (PhanSo p1, PhanSo p2) {
	PhanSo p;
	p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	p.mau = p1.mau * p2.mau;
	return rutGon(p);
}
PhanSo rutGon(PhanSo p) {
	int u = ucln(p.tu, p.mau);
	p.tu /= u;
	p.mau /= u;
	return p;
}
template <typename type>
istream& operator >> (istream& in, Mang <type>& m) {
	in >> m[m.n++];
	return in;
}
template <typename type>
type tinhTongMang(Mang <type> m) {
	type s;
	s = 0;
	for (int i = 0; i < m.n; ++i) {
		s = s + m[i];
	}
	return s;
}
template <typename type>
void result(Mang <type> m) {
	if (m.n == 0) {
		cout << "khong co" << endl;
	}
	else {
		cout << tinhTongMang <type>(m) << endl;
	}
}											