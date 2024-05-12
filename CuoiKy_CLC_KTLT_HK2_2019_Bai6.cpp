#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void TaoBang(int arr[][1000], int hang, int cot) {
    for (int i = 0; i <= hang; i++) {
        for (int j = 0; j <= cot; j++) {
            arr[i][j] = 0;
        }
    }
}

int chuoiConDoiXungDaiNhat(string& s) {
    string sNguoc = s;
    reverse(sNguoc.begin(), sNguoc.end());
    int arr[1000][1000];
    TaoBang(arr, s.length(), sNguoc.length());
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= sNguoc.length(); j++) {
            if (s[i - 1] == sNguoc[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    return arr[s.length()][sNguoc.length()];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int doDaiMax = chuoiConDoiXungDaiNhat(s);
    cout << doDaiMax;
    return 0;
}
