#include <iostream>

#define space ' '
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau + a.mau * b.tu;
    c.mau = a.mau * b.mau;
    return c;
}

int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

PhanSo rutGon(PhanSo ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    PhanSo* arr = new PhanSo[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].tu >> arr[i].mau;
    }
    PhanSo tong = tongPhanSo(arr, n);
    tong = rutGon(tong);
    cout << tong.tu << space << tong.mau << endl;
    delete[] arr;

    return 0;
}
