#include<iostream>

using namespace std;

int catalan(int n);
int main(){
	int n;
	while(cin >> n){
		cout << catalan(n) << endl;
	}
	return 0;
}

int catalan(int n){
	if(n==0||n==1){
		return 1;
	}
	else{
		int tong = 0;
		for(int i = 0;i<n;i++){
			tong += catalan(i)*catalan(n-1-i);
		}
		return tong;
	}
}