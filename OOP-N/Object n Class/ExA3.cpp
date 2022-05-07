#include <iostream>
using namespace std;

class ARRINT1
{
    private:
        int len, a[123456];
    
    public:
        ARRINT1();
        ARRINT1(int);
        ARRINT1(int,int[]);
        int getLen();
        void setLen(int);
        void Input(int,int a[]);
        void Output();
        int getMod(int);
        ARRINT1 getOddNumber();
        ARRINT1 operator + (ARRINT1 a);
};

int main()
{
    int x,y,a[123456],b[123456];
    cin >> x >> y;
    for (int i = 0 ; i < x ; i++)
        cin >> a[i];
    for (int i = 0 ; i < y ; i++)
        cin >> b[i];
    ARRINT1 s1,s2;
    s1.Input(x,a);
    s2.Input(y,b);
    (s1+s2).Output();
    return 0;
}

ARRINT1::ARRINT1()
{
    this->len = 1;
    this->a[0] = 0;
}
ARRINT1::ARRINT1(int n)
{
    this->len = n;
    for (int i = 0 ; i < n ; i++)
        this->a[i] = 1;
}

int ARRINT1::getLen()
{
    return this->len;
}

void ARRINT1::setLen(int n)
{
    this->len = n;
}

void ARRINT1::Input(int len, int a[])
{
    this->setLen(len);
    for (int i = 0 ; i < this->len ; i++)
        this->a[i] = a[i];
}
void ARRINT1::Output()
{
    cout << this->len << ": ";
    for (int i = this->len - 1 ; i >= 0 ; i--)
        cout << this->a[i];
}
int ARRINT1::getMod(int m)
{
    int sum = 0;
    for (int i = 0 ; i < this->len ; i++)
        sum += this->a[i]%m;
    return sum;
}
ARRINT1 ARRINT1::getOddNumber()
{
    int Len = 0, ar[123456];
    for (int i = 0 ; i < this->len ; i++)
        if (this->a[i] % 2 == 1)
            ar[Len++] = this->a[i];
    ARRINT1 res;
    res.Input(Len,ar);
    return res;
}
ARRINT1 ARRINT1::operator + (ARRINT1 a)
{
    int Len = 0, ar[123456], LEN = a.len,t;
    if (LEN < this->len)
        LEN = this->len;
    if (this->len < LEN)
    {
        for (int i = this->len ; i <= LEN ; i++)
            this->a[i] = 0;
    }
    if (a.getLen() < LEN)
    {
        for (int i = a.getLen() ; i <= LEN ; i++)
            a.a[i] = 0;
    }
    for (int i = 0 ; i < LEN ; i++)
    {
        t = 0;
        if (this->len-i-1 >= 0)
            t = this->a[this->len-i-1];
        if (a.getLen()-i-1 >= 0)
            t = t + a.a[a.getLen()-i-1];
        if (t >= 10)
            t-=10;
        ar[LEN-i-1] = t;
    }
    ARRINT1 res;
    res.Input(LEN,ar);
    return res;
}
//#include <bits/stdc++.h>
using namespace std;
class ARRINT1{
	int a[101];
	int n;
	int& operator [] (int k)
	{
		return a[k];
	}
	public:
		void setn(int k)
		{
			n=k;
		}
		friend istream& operator >> (istream& is,ARRINT1& ar)
		{
			for (int i=0;i<ar.n;i++)
				is >> ar[i];
			return is;
		}
		friend ostream& operator << (ostream& os,ARRINT1 ar)
		{
			os << ar.n << ": " ;
			for (int i=ar.n-1;i>=0;i--)
				os << ar[i];
			return os;
		}
		ARRINT1 operator + (ARRINT1 ar)
		{
			ARRINT1 ar1;
			int so=0;
			if (ar.n>n)
			{
				so=ar1.n=ar.n;
				so--;
				for (int i=0;i<ar.n;i++)
					ar1[i]=ar[i];
				for (int i=n-1;i>=0;i--)
				{
					ar1[so]=ar1[so]+a[i];
					if (ar1[so]>=10)
						ar1[so]-=10;
					so--;
				}
			}
			else
			{
				so=ar1.n=n;
				so--;
				for (int i=0;i<n;i++)
					ar1[i]=a[i];
				for (int i=ar.n-1;i>=0;i--)
				{
					ar1[so]+=ar[i];
					if (ar1[so]>=10)
						ar1[so]-=10;
					so--;
				}
			}
			return ar1;
		}
};
int main()
{
	ARRINT1 ar1,ar2;
	int n,k;
	cin >> n >> k;
	ar1.setn(n);
	ar2.setn(k);
	cin >> ar1 >> ar2;
	cout << ar1+ar2;
}