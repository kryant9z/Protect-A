#include <iostream>
#include<cmath>

using namespace std;


int tinhtong(int n, int x);
int main(){
	int n, x;
	cin >> n >> x;
	cout << tinhtong(n, x);
	return 0;
}

int tinhtong(int n, int x){
	if(n==0){
		return 1;
	}
	else{
		return	tinhtong(n-1, x) + pow(x,n);
	}
}