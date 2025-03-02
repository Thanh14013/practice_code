#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, S;
    cin >> n >> S;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1])
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j - a[i - 1]];
            }
        }
    }
    cout << dp[n][S] << endl;
    return 0;
}