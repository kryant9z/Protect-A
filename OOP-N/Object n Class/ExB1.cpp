#include <bits/stdc++.h>
using namespace std;
class ARRINT2{
	int a[100];
	int l;
	public:
		ARRINT2 (int _l=0,int _a[]=new int[1])
		{
			l=_l;
			for (int i=0;i<=_l;i++)
				a[i]=_a[i];
		}
		~ARRINT2(){}
		int setlen(){
			cin >> l;
			return l;
		}
		void getlen(){cout << l << ": ";}
		void khoitao1(int k)
		{
			for (int i=0;i<k;i++)
				a[i]=i+1;
		}
		void khoitao2(string s)
		{
			int k=l-1;
			for (int i=0;i<s.size();i++)
			{
				if (s[i]!=' ')
				{
					a[k]=s[i]-'0';
					k--;
				}
			}
		}
		void xuat()
		{
			for (int i=0;i<l;i++)
				cout << a[i];
		}
};
int main()
{
	ARRINT2 t;
	string s;
	int k=0;
	k=t.setlen();
	cin.ignore();
	getline(cin,s);
	t.getlen();
	if (s=="#")
		t.khoitao1(k);
	else
		t.khoitao2(s);
	t.xuat();
	
}