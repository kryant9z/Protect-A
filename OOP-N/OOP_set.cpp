#include <iostream>
#include<algorithm>
using namespace std;

class Set {
    private:
        int *a;
        int n;
    public:
        void nhap();
        void xuat();
        int getn();
        int getphantu (int i);
};
void Set::nhap() {
    cin >> n;
    a = new int[n];
    for (int i = 0 ; i < n ; ++i) 
    cin >> a[i];
}
void Set::xuat() {
    for (int i = 0 ; i < n ; ++i) 
    cout << a[i] << " ";
}
int Set::getn() {
    return n;
}
int Set::getphantu (int i) {
    return a[i];
}

void giao (Set a , Set b) {
    int c[100];
    int n = 0;
    int dem = 0;
    for (int i = 0 ; i < a.getn() ; ++i) {
        for (int j = 0 ; j < b.getn() ; ++j) {
            if(a.getphantu(i) == b.getphantu(j)) {
                c[n++] = a.getphantu(i);
                ++dem;
                break;
            }
        }
    }
    if (n == 0) 
    cout << 0;
    else {
        sort (c , c + n);
        for (int i = 0 ; i < n ; ++i) 
        cout << c[i] << " ";
    }
}
void hop (Set a , Set b) {
    int c[100];
    int n = 0;
    for (int i = 0 ; i < a.getn() ; ++i) 
    c[n++] = a.getphantu(i);
    for (int i = 0 ; i < b.getn() ; ++i) {
        int dem = 0;
        for (int j = 0 ; j < a.getn() ; ++j) {
            if (b.getphantu(i) == a.getphantu(j)) 
            ++dem;
        }
        if (dem == 0) 
        c[n++] = b.getphantu(i);
    }
    if (n == 0) 
    cout << 0;
    else {
        sort (c , c + n);
        for (int i = 0 ; i < n ; ++i) 
        cout << c[i] << " ";
    }
}

int main() {
    Set a , b;
    a.nhap();
    b.nhap();
    a.xuat();
    cout << endl;
    b.xuat();
    cout << endl;
    giao (a , b);
    cout << endl;
    hop (a , b);
    return 0;
}