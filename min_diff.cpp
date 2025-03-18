#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s = sum / 2;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(s - dp[j]) > abs(s - dp[j] - a[i - 1]))
            {
                dp[i] = dp[j] + a[i - 1];
            }
        }
    }
    cout << dp[n];
    return 0;
}