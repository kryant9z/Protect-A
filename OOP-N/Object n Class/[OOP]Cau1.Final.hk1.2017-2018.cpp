#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
class diem{
    private:
    int x,y;
    public:
    diem(){
        x=0;y=0;
    }
    diem(int a,int b){
        x=a;y=b;
    }
    diem(const diem&d){
        x=d.x;
        y=d.y;
    }
    ~diem(){}
    int getx(){return x;}
    int gety(){return y;}
    void setx(int a){x=a;}
    void sety(int a){y=a;}
    friend istream&operator>>(istream&cin,diem&d){
        cin>>d.x>>d.y;
        return cin;
    }
    friend ostream&operator<<(ostream&cout,diem d){
        cout<<"("<<d.x<<","<<d.y<<")";
        return cout;
    }
    diem operator+(diem a){
        diem kq;
        kq.x=x+a.x;
        kq.y=y+a.y;
        return kq;
    }
    float kcach(diem a){
        return(sqrt(pow(x-a.x,2)+pow(y-a.y,2)));
    }
    bool ktra(int a,int b){
        return (a*x+b*y==0);
    }
};
int main(){
    diem d1,d2;
    cin>>d1>>d2;
    int a,b;
    cin>>a>>b;
    cout<<d1<<endl;
    cout<<d2<<endl;
    cout<<d1+d2<<endl;
    double kq=d1.kcach(d2);
    printf("%.1lf\n",kq);
    
    if(d1.ktra(a,b)==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}