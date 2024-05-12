#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

struct thongtin {
    long long a;
};

void nhap(thongtin &so) {
    cin >> so.a;
}

long long DemSoNguyen(thongtin &so) {
    long long temp = so.a;
    long long count = 0;
    if (so.a <= 0) {
        cin >> so.a;
        temp = so.a;
    }
    while (temp != 0) {
        temp /= 10;
        count++;
    }
    return count;
}

long long TongSoNguyen(thongtin &so) {
    long long sum = 0;
    long long temp = so.a;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

long long timSoNguyenK(thongtin &so) {
    long long k = floor(log2(so.a));
    if (pow(2, k) > so.a) {
        k--;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    thongtin so;
    nhap(so);
    long long DemSo = DemSoNguyen(so);
    cout << DemSo << endl;
    long long TongSo = TongSoNguyen(so);
    cout << TongSo << endl;
    long long timK = timSoNguyenK(so);
    cout  << timK << endl;
    
    return 0;
}
