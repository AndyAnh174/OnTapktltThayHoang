#include <iostream>
#define space ' '
#define endl '\n'
using namespace std;

struct KhachHang {
    int thoiGianBatDau;
    int thoiGianKetThuc;
    int chiPhi;
    bool daPhucVu;
};
void tinhDoanhThu(KhachHang khachHangs[], int n) {
    int tongDoanhThu = 0;
    int soLuongDaPhucVu = 0;
    int thoiGianKetThucCuoiCung = 0;

    for (int i = 0; i < n; ++i) {
        if (!khachHangs[i].daPhucVu && khachHangs[i].thoiGianBatDau >= thoiGianKetThucCuoiCung) {
            khachHangs[i].daPhucVu = true;
            tongDoanhThu += khachHangs[i].chiPhi;
            thoiGianKetThucCuoiCung = khachHangs[i].thoiGianKetThuc;
            soLuongDaPhucVu++;
        }
    }

    cout << soLuongDaPhucVu << space << tongDoanhThu << endl;
    for (int i = 0; i < n; ++i) {
        if (khachHangs[i].daPhucVu) {
            cout << i + 1 << space;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    KhachHang *khachHangs = new KhachHang[n];
    for (int i = 0; i < n; ++i) {
        cin >> khachHangs[i].thoiGianBatDau >> khachHangs[i].thoiGianKetThuc >> khachHangs[i].chiPhi;
        khachHangs[i].daPhucVu = false;
    }
    tinhDoanhThu(khachHangs, n);
    delete[] khachHangs;
    return 0;
}
