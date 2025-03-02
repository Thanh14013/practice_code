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
    vector<int> dp(S + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (j >= a[i])
            {
                dp[j] = dp[j] + dp[j - a[i]];
            }
        }
    }
    cout << dp[S] << endl;
    return 0;
}