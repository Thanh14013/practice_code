#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> p;
    cin >> n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], p[j] + dp[i - j]);
        }
    }
    cout << dp[n] << endl;
}