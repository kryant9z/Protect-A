#include <bits/stdc++.h>
using namespace std;
class Contestant
{
    string id;
    int n;
    int score[100];
public:
    string getID()                  {return id;}
    int getN()                      {return n;}
    int getScore(int x)             {return score[x];}
     
    void setID(string k)            {id=k;}
    void setN(int k)                {n=k;}
    void setScore(int i, int k)     {score[i]=k;}
    void setVal(string _id, int _n, int _score[]){
        id=_id, n=_n;
        for(int i=0; i<n; i++) score[i]=_score[i];
    }
    
    Contestant(string _id="", int _n=0 , int _score [1]= new int [1]){
        id=_id; n=_n;
        for(int i=0; i<n; i++) score[i]=_score[i];
    }
    Contestant(const Contestant &C){
        id=C.id; n=C.n; 
        for(int i=0; i<C.n; i++){
            score[i]=C.score[i];
        }
    }
    ~Contestant(){}
    int operator[](int k)           {return score[k];}
    
    friend istream &operator>>(istream &cin, Contestant &c){
        cin >> c.id >> c.n;// getline thì kq sai ??? Không hiểu! Tức á hmmmm
        for(int i=0; i<c.n; i++) cin >> c.score[i];
        return cin;
    }
    friend ostream &operator<<(ostream &cout, Contestant c){
        cout << c.id << "-" << c.getAC() << "-" << c.getTime();
        return cout;
    }
    int getAC()                             
    {
        int count=0;
        for(int i=0; i<n; i++){
            if(score[i]!=-1) count++;
        }
        return count;
    }
    int getTime()
    {
        int Sum=0;
        // int n=getAC();
        for(int i=0; i<n; i++){
            // Sum+=score[i];
            if (score[i] != -1) Sum += score[i];
        }
        return Sum;
    } 
    bool operator<(Contestant C){
        if(getAC()<C.getAC()) return true;
        if(getAC()==C.getAC() && getTime()>C.getTime()) return true;
        return false;
    }
    bool operator>(Contestant C){
        if(getAC()>C.getAC()) return true;
        if(getAC()==C.getAC() && getTime()<C.getTime()) return true;
        return false;
    }
    bool operator==(Contestant C){
        return (getAC()==C.getAC() && getTime()==C.getTime());
    }
    int ketHop(Contestant C){
        if(*this>C) return 0;
        int X=getAC(), Y=C.getAC();
        if(*this==C && X+1<=n) return 1;
        if(*this<C && getTime()<C.getTime() && X+1<=n) return 1;
        if(*this<C && Y+1<=n) return Y+1-X;
        return -1;
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int c, n, x;
    Contestant X[100], Y, Z;
    string s[10];
    cin >> c >> n;
    for(int i=0; i<c; i++){
        string id;
        X[i].setN(n);
        cin >> id; 
        X[i].setID(id);
        for(int j=0; j<n; j++) 
            cin >> x, X[i].setScore(j,x);
    }
    cin >> s[1] >> s[2];
    // gán cho gọn nè
    for(int i=0; i<n; i++){
        if(X[i].getID() == s[1]) Y=X[i];
        if(X[i].getID() == s[2]) Z=X[i];
    }
    if(Y<Z) cout << "<" << endl;
    else if(Y==Z) cout << "=" << endl;
    else cout << ">" << endl;
    cout << Y.ketHop(Z);
    return 0;
}
