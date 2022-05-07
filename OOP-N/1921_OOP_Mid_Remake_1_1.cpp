#include<bits/stdc++.h>

using namespace std;
class Contestant{
   private:
   string id;
   int n;
   int scores[100];
   
   public:
   Contestant(){// khoi tao k tham so
       id="0"; n=0; scores[0]=0;
   }
   Contestant(string a, int b){// Khoi tao co tham so 
       id=a;
       n=b;
       
   }
   Contestant(const Contestant&c){// Hàm khởi tạo sao chép 
       id=c.id;
       n=c.n;
       for(int i=0;i<n;i++){
           scores[i]=c.scores[i];
       }
   }
   ~Contestant(){};
   friend istream &operator>>(istream &is, Contestant &c){
       is>>c.id;
       for(int i=0;i<c.n;i++){
           is>>c.scores[i];
       }
       return is;
   }
   friend ostream &operator<<(ostream &os, Contestant c){
       os<<c.id<<"-"<<c.getAC()<<"-"<<c.getTime()<<endl;
       return os;
   }
   int getAC(){
       int dem=0;
       for(int i=0;i<n;i++){
           if(scores[i]!=-1){
               dem++;
           }
       }
       return dem;
   }
   int getTime(){
       int s=0;
       for(int i=0;i<n;i++){
           if(scores[i]!=-1){
               s=s+scores[i];
           }
       }
       return s;
   }
    int getn(){//lấy 
        return n;
    }
    void setn(int k){// gán
        n=k;
    }
};


int main()
{
    Contestant c1[100];
    // cin>>c1; cout<<c1;
    int C, N;
    cin>>C>>N;
    for(int i=0;i<C;i++){
        c1[i].setn(N);
        cin>>c1[i];
    }
    for(int i=0;i<C;i++){
        cout<<c1[i];
    }
    return 0;
}
