#include<iostream>

using namespace std;

int tohop(int n, int k);
int main(){
	int n, k;
	cin >> n >> k;
	cout << tohop(n,k);
	return 0;
}

int tohop(int n, int k){
	if(k==n||k ==0){
		return 1;
	}
	else{
		return tohop(n-1,k) + tohop(n-1,k-1);
	}
}