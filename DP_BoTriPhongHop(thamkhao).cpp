#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct CuocHop {
    int id;
    int batDau; 
    int ketThuc; 
};

bool soSanhCuocHop(CuocHop ch1, CuocHop ch2) {
    return ch1.ketThuc < ch2.ketThuc;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    CuocHop cuocHop[10000];
    for (int i = 0; i < N; ++i) {
        cuocHop[i].id = i + 1;
        cin >> cuocHop[i].batDau >> cuocHop[i].ketThuc;
    }

    sort(cuocHop, cuocHop + N, soSanhCuocHop);

    int thoiGianKetThucCuoiCung = cuocHop[0].ketThuc;
    int lichTrinh[10000] = {cuocHop[0].id};
    int kichThuocLichTrinh = 1;

    for (int i = 1; i < N; ++i) {
        if (cuocHop[i].batDau >= thoiGianKetThucCuoiCung) {
            lichTrinh[kichThuocLichTrinh++] = cuocHop[i].id;
            thoiGianKetThucCuoiCung = cuocHop[i].ketThuc;
        }
    }
    cout << kichThuocLichTrinh << endl;
    for (int i = 0; i < kichThuocLichTrinh; ++i) {
        cout << lichTrinh[i] << endl;
    }

    return 0;
}
