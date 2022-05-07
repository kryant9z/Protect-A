#include<iostream>

using namespace std;

template<typename T>
struct M1C
{
	int n;
	T  m[100];
	T& operator [] (int i) {
		return m[i];
	}
};

struct Somoi
{
	int a;
	void operator = (int x) {
		a = x;
	}
};

istream& operator >> (istream& is, Somoi& x);
ostream& operator << (ostream& os, Somoi x);
bool operator == (Somoi p1, Somoi p2);
bool operator > (Somoi p1, Somoi p2);
Somoi operator + (Somoi p1, Somoi p2);
int tinhsomoi(Somoi p);
template<typename T>
void input(M1C<T>& r);
template<typename T>
void maxNum(M1C<T>r);
template<typename T>
T tongmang(M1C<T> r);
template<typename T>
void ketqua();
int main() {
	char t;
	cin >> t;
	switch (t)
	{
	case 'N':
		ketqua<int>();
		break;
	case 'M':
		ketqua<Somoi>();
		break;
	}
	return 0;
}

istream& operator >> (istream& is, Somoi& x) {
	is >> x.a;
	return is;
}
ostream& operator << (ostream& os, Somoi x) {
	os << "[SoMoi] " << x.a;
	return os;
}
bool operator == (Somoi p1, Somoi p2) {
	return tinhsomoi(p1) == tinhsomoi(p2);
}
bool operator > (Somoi p1, Somoi p2) {
	return tinhsomoi(p1) > tinhsomoi(p2);
}
Somoi operator + (Somoi p1, Somoi p2) {
	Somoi kq;
	kq.a = tinhsomoi(p1) + tinhsomoi(p2);
	return kq;
}
int tinhsomoi(Somoi p) {
	int s = 0;
	while (p.a > 0)
	{
		int x = p.a % 10;
		s = s + x;
		p.a /= 10;
	}
	return s;

}
template<typename T>
void input(M1C<T>& r) {
	r.n = 0;
	while (cin >> r.m[r.n]) 
	{
		r.n++;	
	}
}
template<typename T>
void maxNum(M1C<T>r) {
	int dem = 1;
	T max = r.m[0];
	for (int i = 1; i < r.n; i++) {
		if (r.m[i] == max) {
			dem++;
		}
		if (r.m[i] > max) {
			max = r.m[i];
			dem = 1;
		}
	}
	cout << max << endl;
	cout << dem << endl;
}
template<typename T>
T tongmang(M1C<T> r) {
	T s;
	s =0;
	for (int i = 0; i < r.n; i++) {
		s = s + r.m[i];
	}
	return s;
}
template<typename T>
void ketqua() {
	M1C <T> r;
	input<T>(r);
	maxNum<T>(r);
	cout << tongmang <T>(r);
}