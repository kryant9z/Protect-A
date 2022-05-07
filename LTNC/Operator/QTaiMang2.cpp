#include<iostream>

using namespace std;

struct MC2 {
	int n;
	int a[100];
	// hàm [] dùng cho mảng
	int& operator [] (int i) {
		return a[i];
	}
	 void operator = (MC2 m){
        n = m.n;
        for(int i =0 ;i<n;i++){
            a[i]=m[i];
        }
    }
};
istream& operator >> (istream& cin, MC2& m1) {
	cin >> m1.n;
	for (int i = 0; i < m1.n; i++) {
		cin >> m1[i];
	}
	return cin;
}
ostream& operator << (ostream& os, MC2 m1) {
	for (int i = 0; i < m1.n; i++) {
		cout << m1[i] << " ";
	}
	return os;
}
MC2 operator + (MC2 m1, MC2 m2) {
	MC2 kq;
	if (m1.n < m2.n) {
		kq = m2;
		for (int i = m1.n; i < m2.n; i++) {
			m1[i] = 0;
		}
		for (int i = 0; i <= m2.n; i++) {
			kq[i] = m1[i] + m2[i];
		}
	}
	else {
		kq = m1;
		for (int i = m2.n; i <= m1.n; i++) {
			m2[i] = 0;
		}
		for (int i = 0; i < kq.n; i++) {
			kq[i] = m1[i] + m2[i];

		}
		return kq;
	}
}
int main(){
	MC2 m1, m2;
	cin >> m1 >> m2;
	cout << m1 + m2;
	return 0;
}