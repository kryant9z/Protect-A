#include<iostream>
using namespace std;

struct Phanso{
	int tu,mau;
	void operator==(Phanso ps)
	{
		tu=ps.tu;
		mau=ps.mau;
	}
};
istream& operator >> (istream& is,Phanso& ps);
ostream& operator << (ostream& os,Phanso ps);
bool operator!=(Phanso ps1,Phanso ps2);
int ucln(int a, int b);
struct honhop{
	int x;
	Phanso ps;
};
istream& operator >> (istream& is,honhop& h);
ostream& operator << (ostream& os,honhop h);
bool operator!=(honhop h1,honhop h2);
bool operator > (honhop h1,honhop h2);
honhop rgthonhop(honhop h);
int tongthanhphan(honhop h);
Phanso rutgon(Phanso ps);
Phanso rgtphanso(honhop h);
int main()
{
	honhop h1,h2;
	cin >> h1 >> h2;
	cin.ignore();
	string s;
	cin >> s;
	if (h1!=h2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	if (h1>h2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	if (s[0]=='t')
		cout << rgthonhop(h1) << endl << rgthonhop(h2);
	else
		cout << rgtphanso(h1) << endl << rgtphanso(h2);
	return 0;
}
istream& operator >> (istream& is,Phanso& ps)
{
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator << (ostream& os,Phanso ps)
{
	os << ps.tu << "/" << ps.mau;
	return os;
}


bool operator != (Phanso ps1,Phanso ps2)
{
	return (ps1.tu != ps2.tu || ps1.mau != ps2.mau);
}
istream& operator >> (istream& is,honhop& h)
{
	is >> h.x >> h.ps;
	return is;
}
ostream& operator << (ostream& os,honhop h)
{
	os << h.x << " " << h.ps;
	return os;
}
int ucln(int a, int b)
{
	while (b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
Phanso rutgon(Phanso ps)
{
	int uoc=ucln(ps.tu, ps.mau);
	ps.tu/=uoc;
	ps.mau/=uoc;
	return ps;
}
honhop rgthonhop(honhop h)
{
	Phanso ps;
	ps.tu=h.x*h.ps.mau+h.ps.tu;
	ps.mau=h.ps.mau;
	ps=rutgon(ps);
	h.x=ps.tu/ps.mau;
	h.ps.tu=ps.tu%ps.mau;
	h.ps.mau=ps.mau;
	return h;
}
Phanso rgtphanso(honhop h)
{
	Phanso ps;
	ps.tu=h.x*h.ps.mau+h.ps.tu;
	ps.mau=h.ps.mau;
	return rutgon(ps);
}
bool operator !=(honhop h1,honhop h2)
{
	return (h1.x!=h2.x || h1.ps.tu !=h2.ps.tu || h1.ps.mau!=h2.ps.mau);
}
int tongthanhphan(honhop h)
{
	return (h.x+h.ps.tu+h.ps.mau);
}
bool operator > (honhop h1,honhop h2)
{
	return (tongthanhphan(h1)>tongthanhphan(h2));
}
