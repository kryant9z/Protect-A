#include <iostream>

using namespace std;

struct BacHai {
	int a, b, c;
};
struct BacNhat {
	int m, n;
};

istream& operator>>(istream& in, BacHai& p);
ostream& operator<<(ostream& out, BacHai p);
int tinhGiaTri2(BacHai p, int x);
BacHai operator+(BacHai p, BacHai q);
bool operator==(BacHai p, BacHai q);
istream& operator>>(istream& in, BacNhat& p);
ostream& operator<<(ostream& out, BacNhat p);
BacHai operator*(BacNhat p, BacNhat q);
int tinhGiaTri1(BacNhat p, int x);

int main() {
	
	BacHai f1, f2, f5, f6;
	BacNhat f3, f4;
	int x;
	cin >> f1 >> f2 >> f3 >> f4 >> x;
	cout << f1;
	cout << tinhGiaTri2(f1, x) << endl;
	cout << f2;
	cout << tinhGiaTri2(f2, x) << endl;
	f5 = f1 + f2;
	cout << f5;
	cout << tinhGiaTri2(f5, x) << endl;
	f6 = f3 * f4;
	cout << "(" << f3 << ")*(" << f4 << ")=" << f6;
	cout << tinhGiaTri2(f6, x) << endl;
	if (f1 == f2 && f2 == f6) {
		cout << "TRUE3";
	}
	else if (f1 == f6) {
		cout << "TRUE1";
	}
	else if (f2 == f6) {
		cout << "TRUE2";
	}
	else {
		cout << "FALSE";
	}
	
	return 0;
}

istream& operator>>(istream& in, BacHai& p) {
	in >> p.a >> p.b >> p.c;
	return in;
}
ostream& operator<<(ostream& out, BacHai p) {
	out << p.a << "x^2";
	if (p.b >= 0) {
		out << "+";
	}
	out << p.b << "x";
	if (p.c >= 0) {
		out << "+";
	}
	out << p.c << endl;
}
int tinhGiaTri2(BacHai p, int x) {
	return p.a * x * x + p.b * x + p.c;
}
BacHai operator+(BacHai p, BacHai q) {
	BacHai t;
	t.a = p.a + q.a;
	t.b = p.b + q.b;
	t.c = p.c + q.c;
	return t;
}
bool operator==(BacHai p, BacHai q) {
	return (p.a == q.a && p.b == q.b && p.c == q.c);
}
istream& operator>>(istream& in, BacNhat& p) {
	in >> p.m >> p.n;
	return in;
}
ostream& operator<<(ostream& out, BacNhat p) {
	out << p.m << "x";
	if (p.n >= 0) {
		out << "+";
	}
	out << p.n;
}
BacHai operator*(BacNhat p, BacNhat q) {
	BacHai t;
	t.a = p.m * q.m;
	t.b = p.m * q.n + p.n * q.m;
	t.c = p.n * q.n;
	return t;
}
int tinhGiaTri1(BacNhat p, int x) {
	return p.m * x + p.n;
}