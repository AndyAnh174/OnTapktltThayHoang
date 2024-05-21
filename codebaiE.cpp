#include <iostream>
#include <algorithm>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long x;
    cin >> x;

  // Nếu x là số dương
  if (x > 0) {
    // Tìm số lần di chuyển 3 đơn vị tối đa
    int count3 = x / 3;
    // Tìm số lần di chuyển 2 đơn vị tối đa
    int count2 = (x % 3) / 2;
    // Tổng số lần di chuyển
    int count = count3 + count2;
    // Nếu số dư của x chia cho 3 là 1, thì cần thêm 1 lần di chuyển 2 đơn vị
    if ((x % 3) == 1) {
      count++;
    }
    cout << count << endl;
  } else if (x < 0) {
    // Nếu x là số âm, ta tìm số lần di chuyển 3 đơn vị tối đa về bên trái
    int count3 = abs(x) / 3;
    // Tìm số lần di chuyển 2 đơn vị tối đa về bên trái
    int count2 = (abs(x) % 3) / 2;
    // Tổng số lần di chuyển về bên trái
    int count = count3 + count2;
    // Nếu số dư của abs(x) chia cho 3 là 1, thì cần thêm 1 lần di chuyển 2 đơn vị về bên trái
    if ((abs(x) % 3) == 1) {
      count++;
    }
    cout << count << endl;
  } else {
    // Nếu x = 0, thì không cần di chuyển
    cout << 0 << endl;
  }

  return 0;
}