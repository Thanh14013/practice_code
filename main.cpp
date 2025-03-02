#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second; // Nhập (trọng lượng, giá trị)
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++) // Duyệt đúng từ 0 đến W
        {
            if (j >= v[i - 1].first)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][W] << endl; // Xuất giá trị lớn nhất có thể đạt được
    return 0;
}
