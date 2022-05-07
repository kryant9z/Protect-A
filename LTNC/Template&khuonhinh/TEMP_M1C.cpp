#include <iostream>

using namespace std;

template <typename Type>
struct M1C {
	int n;
	Type a[1000];
};

template <typename Type>
void nhap(M1C <Type> &r);
template <typename Type>
void xuat(M1C <Type> r);
template <typename Type>
int tong(M1C <Type> r);

int main() {
	
	M1C <int> arr;
	nhap <int> (arr);
	cout << tong <int> (arr);
	
	return 0;
}

template <typename Type>
void nhap(M1C <Type> &r) {
	r.n = 0;
	while (cin >> r.a[r.n]) {
		r.n++;
	}
}
template <typename Type>
void xuat(M1C <Type> r) {
	for (int i = 0; i < r.n; ++i) {
		cout << r.a[i] << " ";
	}
}
template <typename Type>
int tong(M1C <Type> r) {
	int s = 0;
	for (int i = 0; i < r.n; ++i) {
		s += r.a[i];
	}
	return s;
}