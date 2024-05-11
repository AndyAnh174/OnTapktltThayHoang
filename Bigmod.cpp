#include <iostream>
#define endl '\n'
using namespace std;
long long luythua(long long B, long long P, long long M) {
    long long R = 1;
    B = B % M; 
    while (P > 0) {
        if (P & 1) R = (R * B) % M;
        B = (B * B) % M;
        P >>= 1;
    }
    return R;
}

int main() {
    long long B, P, M;
    while (cin >> B >> P >> M) {
        long long res = luythua(B, P, M);
        cout << res << endl;
    }

    return 0;
}