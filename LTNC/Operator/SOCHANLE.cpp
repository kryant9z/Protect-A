#include <iostream>
#include <cmath>
using namespace std;

struct ChuSoChan {
    int gt, n, len;
    /* gt = giá trị CHỮ SỐ CHẴN
       n = số được nhập
       len = độ dài n */

       //quá tải toán tử <
    bool operator<(ChuSoChan csc) {
        return gt < csc.gt;
    }

};
//CauTruc PhanSo//
istream& operator>>(istream& in, ChuSoChan& csc);
ostream& operator<<(ostream& out, ChuSoChan  csc);

int tongThanhPhan(ChuSoChan csc, bool _cachtinh = 1);

int main() {
    //phần input
    bool cachtinh;
    ChuSoChan a, b;
    cin >> a >> b >> cachtinh;

    //phần output
    cout << a << endl << b << endl;

    if (a < b)
        cout << "true";
    else 
        cout << "false";
    cout << endl;

    cout << tongThanhPhan(a, cachtinh) << endl;
    cout << tongThanhPhan(b, cachtinh);
    return 0;
}

//define
istream& operator>>(istream& in, ChuSoChan& csc) {
    in >> csc.n;
    csc.len = 0;
    csc.gt = 0;
    int tmp = csc.n;

    //tìm độ dài
    while (tmp > 0) {
        ++csc.len;
        tmp /= 10;
    }

    //tìm giá trị CSC
    for (int i = csc.len - 1; i >= 0; i -= 2) {
        csc.gt *= 10;
        tmp = csc.n / pow(10, i);
        csc.gt += tmp % 10;
    }

    return in;
}
ostream& operator<<(ostream& out, ChuSoChan  csc) {
    out << csc.gt;
    return out;
}

int tongThanhPhan(ChuSoChan csc, bool _cachtinh) {
    int kq = 0, tmp;

    if (_cachtinh) { //tổng thành phần CSC
      for (int i = csc.len - 2; i >= 0; i -= 2) {
            tmp = csc.n / pow(10, i);
            kq += tmp % 10;
      
    }
    }
    else{ // tổng thành phần CSL
        for (int i = csc.len - 1; i >= 0; i -= 2) {
            tmp = csc.n / pow(10, i);
            kq += tmp % 10;
        }
    }
    return kq;
}
