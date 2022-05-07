#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

double tinhTong(int n, int x);
long luyThua(int x, int n);
long giaiThua(int n);

int main() {
	int n, x;
	cin >> n >> x;

	// cout << tinhTong(n, x);
	cout << roundf(tinhTong(n, x) * 1000) / 1000 << endl;
	//printf("%.3f\n", tinhTong(n, x));

	return 0;
}

long luyThua(int x, int n){
	if (n == 0){
		return 1;
	}
	else{
		return luyThua(x, n - 1) * x;
	}
}

long giaiThua(int n){
	if (n == 0){
		return 1;
	}
	else{
		return giaiThua(n - 1) * n;
	}
}

double tinhTong(int n, int x){
	if (n == 0){
		return 1 + x;
	}
	else{
		return tinhTong(n - 1, x) + (double)luyThua(x, 2*n + 1)/giaiThua(2*n + 1);
	}
}