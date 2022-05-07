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
		int getDiv(int b);
		ArrInt2 getEvenNumber();
};

int main() {
	ArrInt2 m;
	int x, b;
	cin >> x >> b;
	m.setN(x);
	cin >> m;
	cout << m.getDiv(b) << endl;
	cout << m.getEvenNumber();
	
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
int ArrInt2::getDiv(int b) {
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += ((int)a[i] - 48) / b;
	}
	return s;
}
ArrInt2 ArrInt2::getEvenNumber() {
	ArrInt2 m;
	m.n = 0;
	for (int i = 0; i < n; ++i) {
		if (((int)a[i] - 48) % 2 == 0) {
			m[m.n++] = a[i];
		}
	}
	if (m[m.n-1] == '0') {
		m.n--;
	}
	return m;
}