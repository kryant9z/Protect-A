#include<bits/stdc++.h>
using namespace std;
class NV{
	protected:
	string maso;
	string ten;
    string namsinh;
	string masothue;
	static int ml;
	public:
		virtual void nhap(){
			getline(cin,maso);
			getline(cin,ten);
			getline(cin,namsinh);
			getline(cin,masothue);
		}
		virtual void xuat(){
			cout<<maso<<": "<<ten<<endl;
		}
		virtual int tienluong()=0;
		static void setMl(int k){
			ml=k;
		}
};
class TTG:public NV{
	private:
		int bl,pc;
	public:
			void nhap(){
				NV::nhap();
				cin>>bl>>pc;
			}
			int tienluong(){
				return bl*ml+pc;
			}
			void xuat(){
				NV::xuat();
				cout<<"Loai: Toan thoi gian"<<endl;
				if(masothue=="#")
				cout<<"Ma so thue: "<<"Khong co"<<endl;
				else
				cout<<"Ma so thue:"<<masothue<<endl;
				cout<<"Nam sinh:"<<namsinh<<endl;
				cout<<"Bac: "<<bl<<endl;
				cout<<"Phu cap: "<<pc<<endl;
				int t=tienluong();
				cout<<"Luong: "<<bl<<"*"<<ml<<"+"<<pc<<"="<<t<<" (vnd)"<<endl;
			}
};
class BTG:public NV{
	private:
		static int tc;
		int sg;
	public:
			void nhap(){
			    NV::nhap();
				cin>>sg;
			}
			int tienluong(){
				if(masothue=="#")
				return sg*tc-0.2*sg*tc;
				else
				return sg*tc-0.1*sg*tc;
			}
			void xuat(){
				NV::xuat();
				cout<<"Loai: Ban thoi gian"<<endl;
				if(masothue=="#")
				cout<<"Ma so thue: "<<"Khong co"<<endl;
				else
				cout<<"Ma so thue:"<<masothue<<endl;
				cout<<"Nam sinh:"<<namsinh<<endl;
				cout<<"Thoi gian: "<<sg<<" (gio)"<<endl;
				int t=tienluong();
				if(masothue=="#")
				cout<<"Luong: "<<sg<<"*"<<tc<<"-"<<sg<<"*"<<tc<<"*"<<"20%"<<"="<<t<<" (vnd)"<<endl;
				else
				cout<<"Luong: "<<sg<<"*"<<tc<<"-"<<sg<<"*"<<tc<<"*"<<"10%"<<"="<<t<<" (vnd)"<<endl;
				cout<<endl;
			}
			static void setTC(int k){
				tc=k;
			}
};
int NV::ml=0;
int BTG::tc=0;
int main(){
	vector<NV*>a;
	int n;
	cin>>n;
	int k,t;
	cin>>k>>t;

	for(int i=0;i<n;i++){
			cin.ignore();

		string s;
	
		cin>>s;
		cin.ignore();
		
		if(s=="TTG"){
			a.push_back(new TTG);
		}
		else
			a.push_back(new BTG);
		a[i]->nhap();
			BTG::setTC(t);
				NV::setMl(k);
	}
	cout<<"Bang Tien Luong Cong Ty"<<endl<<endl;
	for(int i=0;i<n;i++){
		a[i]->xuat();
		cout<<endl;
	}
	return 0;
	
}
