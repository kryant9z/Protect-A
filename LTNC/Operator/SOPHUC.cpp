#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

struct SoPhuc {
	double a, b;
	void operator = (int x) {
		a = x;
		b = 0;
	}
};
struct DaySoPhuc {
	int n;
	SoPhuc *p;
	SoPhuc& operator [] (int i) {
		return p[i];
	}
};

istream& operator >> (istream &in, SoPhuc &c);
ostream& operator << (ostream &out, SoPhuc c);
SoPhuc operator + (SoPhuc c1, SoPhuc c2);
SoPhuc operator - (SoPhuc c1, SoPhuc c2);
double modun(SoPhuc c);
istream& operator >> (istream &in, DaySoPhuc &d);
ostream& operator << (ostream &out, DaySoPhuc d);
SoPhuc tongDay(DaySoPhuc d);
SoPhuc hieuDay(DaySoPhuc d);
void modunDay(DaySoPhuc d);

int main() {
	
	DaySoPhuc d;
	cin >> d;
	cout << d << endl;
	modunDay(d);
	cout << endl << tongDay(d);
	
	return 0;
}

istream& operator >> (istream &in, SoPhuc &c) {
	in >> c.a >> c.b;
	return in;
}
ostream& operator << (ostream &out, SoPhuc c) {
	out << "{" << c.a;
	if (c.b >= 0) {
		out << "+";
	}
	out << c.b << "i}";
	return out;
}
SoPhuc operator + (SoPhuc c1, SoPhuc c2) {
	SoPhuc c;
	c.a = c1.a + c2.a;
	c.b = c1.b + c2.b;
	return c;
}
SoPhuc operator - (SoPhuc c1, SoPhuc c2) {
	c2.a *= -1;
	c2.b *= -1;
	return c1 + c2;
}
double modun(SoPhuc c) {
	double m = sqrt(c.a * c.a + c.b * c.b);
	return m;
}
istream& operator >> (istream &in, DaySoPhuc &d) {
	d.n = 0;
	d.p = new SoPhuc [d.n];
	while (in >> d[d.n]) {
		d.n++;
	}
	return in;
}
ostream& operator << (ostream &out, DaySoPhuc d) {
	for (int i = 0; i < d.n; ++i) {
		out << d[i] << " ";
	}
	return out;
}
SoPhuc tongDay(DaySoPhuc d) {
	SoPhuc c;
	c = 0;
	for (int i = 0; i < d.n; ++i) {
		c = c + d[i];
	}
	return c;
}
SoPhuc hieuDay(DaySoPhuc d) {
	SoPhuc c = d[0];
	for (int i = 1; i < d.n; ++i) {
		c = c - d[i];
	}
	return c;
}
void modunDay(DaySoPhuc d) {
	for (int i = 0; i < d.n; ++i) {
		printf("%.2f ", modun(d[i]));
	}
}