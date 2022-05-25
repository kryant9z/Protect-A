// lopSV.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<string>
#include <math.h>

using namespace std;

class nguoi {
protected:
	string HoTen;
	string NamSinh;
	string quequan;
public:
	nguoi() {}
	nguoi(string HT, string NS, string QQ) {
		HoTen = HT;
		NamSinh = NS;
		quequan = QQ;
	}
	nguoi(const nguoi &a) {
		HoTen = a.HoTen;
		NamSinh = a.NamSinh;
		quequan = a.quequan;
	}
	void SetHoTen(string HT) {
		HoTen = HT;
	}
	void SetNamSinh(string NS) {
		NamSinh = NS;
	}
	void Setquequan(string QQ) {
		quequan = QQ;
	}
	string GetHoTen() {
		return HoTen;
	}
	string GetNamSinh() {
		return NamSinh;
	}
	string Getquequan() {
		return quequan;
	}
	void nhap() {
		getline(cin, HoTen);
		getline(cin, NamSinh);
		getline(cin, quequan);
	}
	void xuat() {
		cout << "Ho Ten:" <<HoTen<< endl;
		cout << "Nam Sinh:"<<NamSinh << endl;
		cout <<"Que quan:" <<quequan<< endl;
	}
};
class SV : public nguoi {
private:
	string khoa;
	int Diem[100];

public:
	void nhap()
	{
		int i = 0;
		nguoi::nhap();
		getline(cin, khoa);
	}
	void xuat() {
		//nhap khi chua biet so luong phan tu
		int i = 0;
		while (cin >> Diem[i])
		{
			i++;
		}
		double s = 0;
		nguoi::xuat();
		cout << "Khoa:" << khoa << endl;
		cout << "Diem cac mon:";

		for (int j = 0; j < i; j++)
		{
			cout << Diem[j] << " ";
			s = s + Diem[j];
		}
		double m = s / i;
		//lay 2 chu so thap phan
		cout << "Diem trung binh:" << roundf(m * 100) / 100;
	}
};

int main() {
	SV a;
	a.nhap();
	a.xuat();
	return 0;
}




