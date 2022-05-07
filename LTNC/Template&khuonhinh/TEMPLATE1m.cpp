#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct oxy {
	int x, y;
};
struct oxyz {
	int x, y, z;
};
istream& operator >> (istream& in, oxy& a);
ostream& operator << (ostream& out, oxy a);
double operator - (oxy a, oxy b);
bool operator < (oxy a, oxy b);
istream& operator >> (istream& in, oxyz& a);
ostream& operator << (ostream& out, oxyz a);
double operator - (oxyz a, oxyz b);
bool operator < (oxyz a, oxyz b);
template<typename T>
struct mang {
	int n;
	T ptu[100];
	T& operator[](int x) {
		return ptu[x];
	}
	void operator = (mang a) {
		n = a.n;
		for (int i = 0; i < a.n; i++) {
			ptu[i] = a[i];
		}
	}
};
template<typename T>
istream& operator >> (istream& in, mang<T>& a);
template<typename T>
ostream& operator << (ostream& out, mang<T> a);
template<typename T>
double max(mang<T> a);
template<typename T>
void giam(mang<T> a);
template<typename T>
void tang(mang<T> a);
int main() {
	string s;
	mang<oxy> a;
	mang<oxyz> b;
	a.n = 0;
	b.n = 0;
	while (cin >> s) {
		if (s == "Oxy") {
			cin >> a;
			a.n++;
		}
		else if (s == "Oxyz") {
			cin >> b;
			b.n++;
		}
	}
	tang<oxy>(a);
	giam<oxyz>(b);
	cout << max < oxy>(a) << endl << max<oxyz>(b);


	
}
istream& operator >> (istream& in, oxy& a) {
	in >> a.x >> a.y;
	return in;
}
ostream& operator << (ostream& out, oxy a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}
double operator - (oxy a, oxy b) {
	return round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))*1000)/1000;
}
bool operator < (oxy a, oxy b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}
istream& operator >> (istream& in, oxyz& a) {
	in >> a.x >> a.y >> a.z;
	return in;
}
ostream& operator << (ostream& out, oxyz a) {
	out << "(" << a.x << "," << a.y << "," << a.z << ")";
	return out;
}
double operator - (oxyz a, oxyz b) {
	return round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2))*1000)/1000;
}
bool operator < (oxyz a, oxyz b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		if (a.y != b.y) {
			return a.y < b.y;
		}
		else {
			return a.z < b.z;
		}
	}
}
template<typename T>
istream& operator >> (istream& in, mang<T>& a) {
	in >> a[a.n];
	return in;
}
template<typename T>
ostream& operator << (ostream& out, mang<T> a) {
	for (int i = 0; i < a.n; i++) {
		out << a[i] << " ";
	}
	return out;
}
template<typename T>
double max(mang<T> a) {
	double max = -10;
	for (int i = 0; i < a.n; i++) {
		for (int j = i + 1; j < a.n; j++) {
			double c = a[i] - a[j];
			if (c > max) {
				max = c;
			}
		}
	}
	return max;
}
template<typename T>
void giam(mang<T> a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = i + 1; j < a.n; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
		cout << a[i] << " ";
	}
	cout << endl;
}
template<typename T>
void tang(mang<T> a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = i + 1; j < a.n; j++) {
			if (!(a[i] < a[j])) {
				swap(a[i], a[j]);
			}
		}
		cout << a[i] << " ";
	}
	cout << endl;
}