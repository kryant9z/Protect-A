#include<iostream>
#include<vector>

using namespace std;

struct Phanso {
	int tu, mau;
};

istream& operator >> (istream& is, Phanso& p);
ostream& operator << (ostream& os, Phanso p);
 
Phanso operator + (Phanso p1, Phanso p2);
int ucln(int a, int b);
Phanso rutgon(Phanso p);
int main() {
	vector<Phanso>v;
	Phanso x;
	while (cin >> x)
	{
		v.push_back(x);
	}

	Phanso s = v[0];
	for (int i = 1; i < v.size(); i++) {
		s = s + v[i];
	}
	cout << s;
	return 0;
}

istream& operator >> (istream& is, Phanso& p) {
	is>> p.tu >> p.mau;
	return is;
}
ostream& operator << (ostream& os, Phanso p) {
	cout << p.tu << "/" << p.mau;
	return os;
}

Phanso operator + (Phanso p1, Phanso p2) {
	Phanso kq;
	kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	kq.mau = p1.mau * p2.mau;
	return rutgon(kq);
}
int ucln(int a, int b) {
	while (b !=0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Phanso rutgon(Phanso p) {
	int d = ucln(p.tu, p.mau);
	p.tu /= d;
	p.mau /= d;
	return p;
}