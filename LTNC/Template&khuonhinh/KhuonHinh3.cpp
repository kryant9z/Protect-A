#include <iostream>

using namespace std;

template <typename type>
struct Mang {
	int n = 0;
	type a[100];
	type& operator [] (int i) {
		return a[i];
	}
	void operator = (type x) {
		a[n++] = x;
	}
};
struct PhanSo {
	int tu, mau;
};

template <typename type>
istream& operator >> (istream &in, Mang <type> &m);
istream& operator >> (istream &in, PhanSo &p);
ostream& operator << (ostream &out, PhanSo p);
bool operator < (PhanSo p1, PhanSo p2);
template <typename type>
type minNum(Mang <type> m);
template <typename type> void result(Mang <type> m);

int main() {
	
	char t;
	Mang <int> m1;
	Mang <double> m2;
	Mang <PhanSo> m3;
	while (cin >> t) {
		if (t == 'a') {
			cin >> m1;
		}
		else if (t == 'b') {
			cin >> m2;
		}
		else {
			cin >> m3;
		}
	}
	result <int> (m1);
	result <double> (m2);
	result <PhanSo> (m3);
	
	return 0;
}

template <typename type>
istream& operator >> (istream &in, Mang <type> &m) {
	in >> m[m.n++];
	return in;
}
istream& operator >> (istream &in, PhanSo &p) {
	in >> p.tu >> p.mau;
	return in;
}
ostream& operator << (ostream &out, PhanSo p) {
	out << p.tu << "/" << p.mau;
	return out;
}
bool operator < (PhanSo p1, PhanSo p2) {
	return (p1.tu * p2.mau < p2.tu * p1.mau);
}
template <typename type>
type minNum(Mang <type> m) {
	type _min = m[0];
	for (int i = 1; i < m.n; ++i) {
		if (m[i] < _min) {
			_min = m[i];
		}
	}
	return _min;
}
template <typename type> 
void result(Mang <type> m) {
	if (m.n == 0) {
		cout << "khong co" << endl;
	}
	else {
		cout << minNum <type> (m) << endl;
	}
}