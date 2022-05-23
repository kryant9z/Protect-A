#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Diem{
	int x, y;
public:
	// hàm khong có tham so
	diem(){
		x = 0;
		y = 0;
	}
	// hàm có tham số
	diem(int a, int b){
		x = a;
		y = b;
	}
	//hàm sao chép
	diem(const Diem& d){
		x = d.x;
		y = d.y;

	}

	~Diem(){}
	// khỏi tạo hàm get- set
	int getx(){
		return x;
	}

	int gety(){
		return y;
	}
	void setx(int a){
		x = a;
	}
	void sety(int b){
		y = b;
	}

	friend istream& operator >> (istream& is, Diem& d){
		is >> d.x >> d.y;
		return is;
	}
	friend ostream& operator << (ostream& os, Diem d){
		os << "(" << d.x <<"," << d.y <<")";
		return os;
	}
	Diem operator + (Diem a){
		Diem kq;
		kq.x = x+a.x;
		kq.y = y+a.y;
		return kq;
	}
	float kcach(Diem a){
		return (sqrt(pow(x-a.x,2)+pow(y-a.y,2)));
	}
	bool ktra(int a, int b){
		return (a*x+b*y == 0);
	}

};
int main(){
	Diem d1, d2;
	cin >> d1 >> d2;
	double kq;
	int a, b;
	cin >> a >> b;
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d1+d2 << endl;
	kq = d1.kcach(d2);
	cout << fixed << setprecision(2) << kq << endl;
	if(d1.ktra(a,b)== true)
	cout << "TRUE";
	else{
		cout << "NO";
	}

	return 0;
}