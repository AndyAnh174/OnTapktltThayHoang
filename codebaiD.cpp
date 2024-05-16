#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000; // Giới hạn tối đa cho n
int a[MAX_N];
long long dp[MAX_N];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    long long maxsum = a[0];
    dp[0] = a[0];

    for (int i = 1; i < n; i++) 
    {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) 
            if (a[i] <= a[j]) 
                dp[i] = max(dp[i], dp[j] + a[i]);
        maxsum = max(maxsum, dp[i]);
    }

    cout << maxsum << endl;
    return 0;
}

