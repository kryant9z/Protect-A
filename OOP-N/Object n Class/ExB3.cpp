#include <iostream>

using namespace std;

class ArrInt2 {
	int n;
	char a[100];
	public:
		void setN(int k);
		int getN();
		char& operator [] (int i);
		ArrInt2(int _n = 1, char _a[] = new char [1]);
		ArrInt2(const ArrInt2 &m);
		~ArrInt2();
		friend istream& operator >> (istream &in, ArrInt2 &m);
		friend ostream& operator << (ostream &out, ArrInt2 m);
		ArrInt2 operator - (ArrInt2 m);
};
char subChar(char x, char y);

int main() {
	ArrInt2 p, q;
	int x, y;
	cin >> x >> y;
	p.setN(x);
	q.setN(y);
	cin >> p >> q;
	cout << p - q;
	
	return 0;
}

void ArrInt2::setN(int k) {n = k;}
int ArrInt2::getN() {return n;}
char& ArrInt2::operator [] (int i) {return a[i];}
ArrInt2::ArrInt2(int _n, char _a[]) {
	n = _n;
	for (int i = 0; i < n; ++i) {
		a[i] = _a[i];
	}
}
ArrInt2::ArrInt2(const ArrInt2 &m) {
	n = m.n;
	for (int i = 0; i < n; ++i) {
		a[i] = m.a[i];
	}
}
ArrInt2::~ArrInt2() {};
istream& operator >> (istream &in, ArrInt2 &m) {
	for (int i = m.n - 1; i >= 0; --i) {
		in >> m[i];
		if (m[i] == '#') {
			for (int j = 0; j < m.n; ++j) {
				m[j] = (char)(j + 49);
			}
			break;
		}
	}
	return in;
}
ostream& operator << (ostream &out, ArrInt2 m) {
	out << m.n << ": ";
	for (int i = 0; i < m.n; ++i) {
		out << m[i];
	}
	return out;
}
ArrInt2 ArrInt2::operator - (ArrInt2 m) {
	ArrInt2 p;
	if (n > m.n) {
		p = *this;
		for (int i = 0; i < m.n; ++i) {
			p[i] = subChar(p[i], m[i]);
		}
	}
	else {
		p = m;
		for (int i = 0; i < n; ++i) {
			p[i] = subChar(p[i], a[i]);
		}
	}
	return p;
}
char subChar(char x, char y) {
	int s;
	s = (int)x - (int)y;
	if (s < 0) {
		s *= -1;
	}
	return (char)(s + 48);
}