#include <iostream>
#include <string>

using namespace std;

struct Date {
	int d, m, y;
};

istream& operator>>(istream& in, Date& a);
ostream& operator<<(ostream& out, Date a);
bool ktNamNhuan(int a);
int tinhSoNgay(Date a);
string timThu(Date a);
Date ngayKeTiep(Date a);
int maxDay(int a, int b);
bool operator==(Date a, Date b);
bool ngayCungThu(Date a, Date b);
bool operator<(Date a, Date b);
int operator-(Date a, Date b);
int soNamNhuan(int a);
int soNgay(Date a);

int main() {
	
	Date a, b;
	cin >> a >> b;
	cout << a << " " << timThu(a) << " " << tinhSoNgay(a) << " " << ngayKeTiep(a) << " ";
	if (ktNamNhuan(a.y)) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	cout << b << " " << timThu(b) << " " << tinhSoNgay(b) << " " << ngayKeTiep(b) << " ";
	if (ktNamNhuan(b.y)) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	if (ngayCungThu(a, b)) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}
	if (a < b) {
		cout << "1 < 2" << endl;
	}
	else if (b < a) {
		cout << "1 > 2" << endl;
	}
	else {
		cout << "1 = 2" << endl;
	}
	cout << a - b;
	
	return 0;
}

istream& operator>>(istream& in, Date& a) {
	in >> a.d >> a.m >> a.y;
	return in;
}
ostream& operator<<(ostream& out, Date a) {
	if (a.d < 10) {
		cout << 0;
	}
	cout << a.d << "/";
	if (a.m < 10) {
		cout << 0;
	}
	cout << a.m << "/";
	cout << a.y;
}
bool ktNamNhuan(int a) {
	return ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0));
}
int tinhSoNgay(Date a) {
	int n;
	n = a.d;
	for (int i = 1; i < a.m; ++i) {
		n += maxDay(i, a.y);
	}
	return n;
}
string timThu(Date a) {
	if (a.m < 3) {
		a.m += 12;
		a.y -= 1;
	}
	int n = (a.d + 2 * a.m + (3 * (a.m + 1)) / 5 + a.y + (a.y / 4)) % 7;
	switch (n) {
		case 0:
			return "Sunday";
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
	}
}
Date ngayKeTiep(Date a) {
	Date b;
	b.d = a.d + 1;
	b.m = a.m;
	b.y = a.y;
	if (b.d > maxDay(a.m, a.y)) {
		b.m++;
		b.d = 1;
	}
	if (b.m > 12) {
		b.y++;
		b.m = 1;
	}
	return b;
}
int maxDay(int a, int b) {
	switch (a) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		default:
			if (ktNamNhuan(b)) {
				return 29;
			}
			return 28;
	}
}
bool operator==(Date a, Date b) {
	return (a.d == b.d && a.m == b.m && a.y == b.y);
}
bool ngayCungThu(Date a, Date b) {
	return (timThu(a) == timThu(b));
}
bool operator<(Date a, Date b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			return (a.d < b.d);
		}
		else {
			return (a.m < b.m);
		}
	}
	else {
		return (a.y < b.y);
	}
}
int operator-(Date a, Date b) {
	if (a < b) {
		return soNgay(b) - soNgay(a);
	}
	else {
		return soNgay(a) - soNgay(b);
	}
}
int soNamNhuan(int a) {
	return (a - 1) / 400 + (a - 1) / 4 - (a - 1) / 100;
}
int soNgay(Date a) {
	int n = soNamNhuan(a.y) * 366 + (a.y - 1 - soNamNhuan(a.y)) * 365;
	for (int i = 1; i < a.m; ++i) {
		n += maxDay(i, a.y);
	}
	n += a.d - 1;
	return n;
}