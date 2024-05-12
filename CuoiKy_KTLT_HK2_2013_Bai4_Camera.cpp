#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

const int max_size = 200; 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M, N, X;
    cin >> M >> N >> X;

    bool vung[max_size][max_size] = {false};
    for (int i = 0; i < X; i++) {
        int x, y;
        cin >> x >> y;
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (x + dx >= 0 && x + dx < M && y + dy >= 0 && y + dy < N &&
                    abs(dx) + abs(dy) <= 2) {
                    vung[x + dx][y + dy] = true;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (vung[i][j]) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}