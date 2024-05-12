#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

struct PhanSo {
    cpp_int tu;
    cpp_int mau;
};

PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau + a.mau * b.tu;
    c.mau = a.mau * b.mau;
    return c;
}

cpp_int gcd(cpp_int a, cpp_int b) {
    while (b != 0) {
        cpp_int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

PhanSo rutGon(PhanSo ps) {
    if (ps.tu == 0) { 
        return ps;
    }

    if (ps.mau < 0) { 
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }

    cpp_int ucln = gcd(abs(ps.tu), abs(ps.mau)); 
    ps.tu /= ucln;
    ps.mau /= ucln;
    return ps;
}

PhanSo tongPhanSo(PhanSo* arr, int n) {
    PhanSo sum = arr[0];
    for (int i = 1; i < n; ++i) {
        sum = cong(sum, arr[i]);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    PhanSo* arr = new PhanSo[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].tu >> arr[i].mau;
    }
    PhanSo tong = tongPhanSo(arr, n);
    tong = rutGon(tong);
    cout << tong.tu << " " << tong.mau << endl;
    delete[] arr;

    return 0;
}
