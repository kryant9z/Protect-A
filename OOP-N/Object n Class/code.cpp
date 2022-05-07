#include<iostream>
#include<string>

using namespace std;

class Hocsinh {
	string name;
	double dv, dt, dtb;
public:

	void nhap(){
		cin.ignore();
		getline(cin, name);
		cin >> dv;
		cin >> dt;
	}
	void xuat(){
		cout << name << endl;
		cout << xeploai();
	}

	string hoten(){
		return name;
	}
	double diemt(){
		return dt;
	}
	double diemv(){
		return dv;
	}
	string xeploai(){
		if(dtb >= 8.0){
			return "Gioi";
		}
		if(dtb >= 7.0){
			return "Kha";
		}
		if(dtb >=5.0){
			return "Trung binh";
		}
		return "Yeu";
	}
	double tinhtb(){
		return dtb = (dv+dt)/2;
	}

	void gangiatri(Hocsinh a){
		dt =a.dt;
		dv = a.dv;
		dtb =a.dtb;
		name = a.name;
	}
	bool sosanh(Hocsinh a){
		return dtb > a.dtb;
	}
};
int main(){
	Hocsinh a[100], max;
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		a[i].nhap();
		a[i].tinhtb();
	}
	max.gangiatri(a[0]);
	for(int i =1;i<n;i++){
		if(a[i].sosanh(max)){
			max.gangiatri(a[i]);
		}
	}
	max.xuat();
	return 0;
}