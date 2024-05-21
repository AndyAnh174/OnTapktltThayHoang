#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long B, P, M;
    long long ans = 1;
        B=B%M;
    for(;cin >> B >> P >> M;){
    for ( ;0 < P;) {
        if(P&1) ans = (ans*B)%M;
        B=(B*B)%M;
        P>>=1;
    }
    }
    cout <<ans<<endl;
    return 0;
}