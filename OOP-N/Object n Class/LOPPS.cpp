#include<iostream>

using namespace std;

class Phanso {
private:
	int tu, mau;
public:

	void setTu(int _tu);
	void setMau(int _mau);

	int getTu();
	int getMau();

	Phanso();
	~Phanso();
	Phanso(int _tu, int _mau);
	void nhap();
	void xuat();
	Phanso rutgon();
	Phanso nghichdao();
	Phanso cong(Phanso p);
	Phanso tru(Phanso p);
	Phanso nhan(Phanso p);
	Phanso chia(Phanso p);
	Phanso congvsk(int k);
};

int ucln(int a, int b);
int main() {
	Phanso a, b, c;
	int k;
	a.nhap();
	cin >> k;
	cout << a.getTu() << endl;
	cout << a.getMau() << endl;
	a.nghichdao().xuat();
	cout << endl;
	a.rutgon().xuat();
	cout << endl;
	b = a.congvsk(k);
	b.xuat();
	cout << endl;
	c = a.nhan(b);
	c.rutgon().xuat();
	return 0;
}

void Phanso::setTu(int _tu) {
	tu = _tu;
}
void Phanso::setMau(int _mau) {
	mau = _mau;
}

int Phanso::getTu() {
	return tu;
}
int Phanso::getMau() {
	return mau;
}
Phanso::Phanso() {

}
Phanso::~Phanso() {

}
Phanso::Phanso(int _tu, int _mau) {
	tu = _tu;
	mau = _mau;
}
void Phanso::nhap() {
	int _tu, _mau;
	cin >> _tu >> _mau;
	Phanso::setTu(_tu);
	Phanso::setMau(_mau);
}
void Phanso::xuat() {
	cout << Phanso::getTu() << "/" << Phanso::getMau();
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
Phanso Phanso::rutgon() {
	int d = ucln(tu, mau);
	return Phanso(tu / d, mau / d);

}
Phanso Phanso::nghichdao() {
	return Phanso(mau, tu);
}
Phanso Phanso::cong(Phanso p) {
	return Phanso(tu * p.mau + mau * p.tu, mau * p.mau);
}
Phanso Phanso::tru(Phanso p) {
	return Phanso(tu * p.mau - mau * p.tu, mau * p.mau);
}
Phanso Phanso::nhan(Phanso p) {
	return Phanso(tu * p.tu, mau * p.mau);
}
Phanso Phanso::chia(Phanso p) {
	return Phanso(tu * p.mau, mau * p.tu);
}
Phanso Phanso::congvsk(int k) {
	return Phanso(tu + k, mau + k);
}