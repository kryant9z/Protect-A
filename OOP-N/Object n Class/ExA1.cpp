#include <iostream>


using namespace std;


class ArrInt1 {
	int n;
	char a[100];
public:
	void setN(int k);
	int getN();
	ArrInt1(int _n = 1, char _a[] = new char [1]);
	ArrInt1(const ArrInt1 &m);
	~ArrInt1();
	char& operator [] (int i);
	friend istream& operator >> (istream &in, ArrInt1 &m);
	friend ostream& operator << (ostream &out, ArrInt1 &m);
};

int main() {
	ArrInt1 m;
	cin >> m;
	cout << m;

	return 0;
}

void ArrInt1::setN(int k){
	n = k;
}
int ArrInt1::getN() {
	return n;
}
ArrInt1::ArrInt1(int _n, char _a[]) {
		n = _n;
		for (int i = 0; i < n; ++i) {
		a[i] = _a[i];
	}
}
ArrInt1::ArrInt1(const ArrInt1 &m) {
		n = m.n;
	for (int i = 0; i < n; ++i) {
		a[i] = m.a[i];
	}
}
ArrInt1::~ArrInt1() {};
char& ArrInt1::operator [] (int i) {
	return a[i];
}
istream& operator >> (istream &is, ArrInt1 &m) {
	is >> m.n;
	for (int i = m.n - 1; i >= 0; --i) {

		is >> m[i];
		if (m[i] == '#') {
			for (int j = 0; j < m.n; ++j) {
				m[j] = '1';
			}
			break;
		}
	}
	return is;
}
ostream& operator << (ostream &out, ArrInt1 &m) {
	out << m.n << ": ";
	for (int i = 0; i < m.n; ++i) {
		out << m[i];
	}
	return out;
}


