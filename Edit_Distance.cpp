#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    string B;
    getline(cin, A);
    getline(cin, B);
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 0; i <= a; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= b; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }

    cout << dp[a][b] << endl;
    return 0;
}