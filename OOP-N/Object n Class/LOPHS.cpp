// ham nhap xuat
// ham van toan tb
//ham so sanh
#include<iostream>
#include<string>

using namespace std;

class Hocsinh {
	string name;
	double dv, dt, dtb;
public:

	void nhap();
	void xuat();

	string hoten();
	double diemv();
	double diemt();
	double tinhtb();
	string xeploai();
	void gangiatri(Hocsinh a);
	bool sosanh(Hocsinh a);

};
int main() {
	Hocsinh a[100], max;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			a[i].nhap();
			a[i].tinhtb();
		}
		max.gangiatri(a[0]);
		for (int i = 1; i < n; i++) {
			if (a[i].sosanh(max)) {
				max.gangiatri(a[i]);
			}
		}
		max.xuat();

	return 0;
}
void Hocsinh::nhap() {
	cin.ignore();
	getline(cin, name);
	cin >> dv;
	cin >> dt;
}
void Hocsinh::xuat() {
	cout << name << endl;
	cout << xeploai();
}
void Hocsinh::gangiatri(Hocsinh a) {
	dv = a.dv;
	dt = a.dt;
	dtb = a.dtb;
	name = a.name;
}
string Hocsinh::hoten() {
	return name;
}
double Hocsinh::diemv() {
	return dv;
}
double Hocsinh::diemt() {
	return dt;
}
double Hocsinh::tinhtb() {
	
	return dtb = (dt + dv) / 2;
}
string Hocsinh::xeploai() {
	if (dtb >= 8.0) {
		return "Gioi";
	}
	if (dtb >= 7.0) {
		return "Kha";
	}
	if (dtb >= 5.0) {
		return "Trung binh";
	}
	return "Yeu";
}
bool Hocsinh::sosanh(Hocsinh a) {
	return (dtb > a.dtb);
}
