#include<iostream>
#include<cmath>
using namespace std;
struct Phanso {
	int tu, mau;
	void operator = (Phanso p) {
		tu = p.tu;
		mau = p.mau;
	}
	void operator = (int x) {
		tu = x;
		mau = 1;
	}
};
istream& operator >> (istream& is, Phanso& p);
ostream& operator << (ostream& os, Phanso p);

Phanso rutgon(Phanso& p);
Phanso operator + (Phanso p1, Phanso p2);
bool operator == (Phanso p1, Phanso p2);
bool operator != (Phanso p1, Phanso p2);
int ucln(int a, int b);
int main() {
	Phanso p1, p2;
	cin >> p1 >> p2;
	if (p1.mau == 0) {
		cout << " ";
	}
	else
	{
		cout << p1 + p2;
	}
	return 0;
}
ostream& operator << (ostream& os, Phanso p) {
	os << p.tu << "/" << p.mau;
	return os;
}
istream& operator >> (istream& is, Phanso& p) {
	is >> p.tu >> p.mau;
	return is;
}		

Phanso rutgon(Phanso& p) {
	int x = ucln(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
	return p;
}

Phanso operator + (Phanso p1, Phanso p2) {
	Phanso kq;
			kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
			kq.mau = p1.mau * p2.mau;
	return rutgon(kq);
}

bool operator == (Phanso p1, Phanso p2) {
	return p1.tu * p2.mau == p2.tu * p1.mau;
}
bool operator != (Phanso p1, Phanso p2) {
	return !(p1 == p2);
}
int ucln(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}