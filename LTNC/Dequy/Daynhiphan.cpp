#include<iostream>

using namespace std;

int n, a[100];
int nhiphan(int i);
int main(){
	cin >> n;
	nhiphan(0);
	return 0;
}
int nhiphan(int i)
{
	if(i==n){
		for(int k =0;k<n;k++){
			cout << a[k];
		}
		cout << endl;
	}
	else
	{
		for(int k =0;k<=1;k++){
			a[i] =  k;
			nhiphan(i+1);	
		}
	}
}