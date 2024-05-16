#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100; // Giới hạn tối đa cho n và m
int matrix[MAX_N][MAX_N];

int CT(int n, int m, int matrix[MAX_N][MAX_N]) 
{
    int mr[MAX_N];
    int mc[MAX_N];

    for (int i = 0; i < n; ++i) 
        mr[i] = INT_MIN;
    for (int j = 0; j < m; ++j) 
        mc[j] = INT_MAX;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
        {
            mr[i] = max(mr[i], matrix[i][j]);
            mc[j] = min(mc[j], matrix[i][j]);
        }
    
    int count = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (matrix[i][j] == mr[i] && matrix[i][j] == mc[j]) 
                count++;
                
    return count;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> matrix[i][j];

    int result = CT(n, m, matrix);
    cout << result << endl;

    return 0;
}
p
