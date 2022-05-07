#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Diem {
	int x, y;
};
struct DTron {
	Diem o;
	double r;
};

const double pi = 3.14;

istream& operator>>(istream& in, Diem& a);
ostream& operator<<(ostream& out, Diem a);
double operator-(Diem a, Diem b);
bool operator==(Diem a, Diem b);
istream& operator>>(istream& in, DTron& c);
ostream& operator<<(ostream& out, DTron c);
bool operator==(DTron c1, DTron c2);
double chuVi(DTron c);
bool operator<(DTron c1, DTron c2);
double operator+(DTron c1, DTron c2);
double dienTich(DTron c);
string vtDTron(DTron c1, DTron c2);

int main() {
	
	DTron c1, c2;
	cin >> c1 >> c2;
	cout << c1 << endl << c2 << endl;
	cout << roundf((c1 + c2) * 1000) / 1000 << endl;
	if (c1 == c2) {
		cout << "1 = 2" << endl;
	}
	else if (c1 < c2) {
		cout << "1 < 2" << endl;
	}
	else {
		cout << "1 > 2" << endl;
	}
	cout << vtDTron(c1, c2);
	
	return 0;
}

istream& operator>>(istream& in, Diem& a) {
	in >> a.x >> a.y;
	return in;
}
ostream& operator<<(ostream& out, Diem a) {
	out << "(" << a.x << "," << a.y << ")";
}
double operator-(Diem a, Diem b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool operator==(Diem a, Diem b) {
	return (a.x == b.x && a.y == b.y);
}
istream& operator>>(istream& in, DTron& c) {
	in >> c.o >> c.r;
	return in;
}
ostream& operator<<(ostream& out, DTron c) {
	out << c.o << " " << c.r;
}
bool operator==(DTron c1, DTron c2) {
	return (chuVi(c1) == chuVi(c2));
}
double chuVi(DTron c) {
	return 2 * pi * c.r;
}
bool operator<(DTron c1, DTron c2) {
	return (chuVi(c1) < chuVi(c2));
}
double operator+(DTron c1, DTron c2) {
	return dienTich(c1) + dienTich(c2);
}
double dienTich(DTron c) {
	return pi * c.r * c.r;
}
string vtDTron(DTron c1, DTron c2) {
	double t, rh, rt;
	t = c1.o - c2.o;
	rh = abs(c1.r - c2.r);
	rt = c1.r + c2.r;
	if (t > rh && t < rt) {
		return "C";
	}
	if (t == rh) {
		return "TXT";
	}
	if (t == rt) {
		return "TXN";
	}
	if (t == 0) {
		return "DT";
	}
	if (t > rt) {
		return "NN";
	}
	if (t < rh) {
		return "DN";
	}
}