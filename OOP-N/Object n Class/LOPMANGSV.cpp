#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Diem {
private:
	int n;
	float a[101];
public:
	friend istream& operator>>(istream &is, Diem &d);
	friend ostream& operator<<(ostream &os, Diem d);
	float tinhDTB();
};
istream& operator>>(istream &is, Diem &d) {
	while (is >> d.a[d.n])
		d.n++;
	return is;
}
ostream& operator<<(ostream &os, Diem d) {
	for (int i = 0; i<d.n; i++)
		os << d.a[i];
	return os;
}
float Diem::tinhDTB() {
	float res = 0;
	for (int i = 0; i<n; i++)
		res += a[i];
	return (float)res / n;
}
//-----------------------------------------//
class SinhVien {
private:
	string ten;
	string mssv;
	Diem diem;
public:
	friend istream& operator>>(istream &is, SinhVien &sv);
	friend ostream& operator<<(ostream &os, SinhVien sv);
	float getDiem();
};

istream& operator>>(istream &is, SinhVien &sv) {
	is.ignore();
    is.clear();
	getline(is, sv.ten);
	is >> sv.mssv;
	is >> sv.diem;
	return is;
}

ostream& operator<<(ostream &os, SinhVien sv) {
	os << "Ho Ten: " << sv.ten << "\n";
	os << "Ma Sinh Vien: " << sv.mssv << "\n";
	printf("DTB: %.1f\n", sv.getDiem());
	return os;
}
float SinhVien::getDiem() {
	return diem.tinhDTB();
}

//----------------------------------------//
class MSV {
private:
	int n;
	SinhVien a[101];
public:
	friend istream& operator>>(istream &is, MSV & sv);
	SinhVien diemCao();
};

istream& operator>>(istream &is, MSV & sv) {
	is >> sv.n;
	for (int i = 0; i<sv.n; i++)
		is >> sv.a[i];
	return is;

}
SinhVien MSV::diemCao() {
	float ans = 0.0;
	int ind;
	for (int i = 0; i<n; i++) {
		if (a[i].getDiem()>ans) {
			ans = max(ans, a[i].getDiem());
			ind = i;
		}
	}
	return a[ind];
}

int main() {
	MSV sv;
	cin >> sv;
	cout << sv.diemCao();
	return 0;
}