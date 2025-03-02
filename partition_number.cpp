#include <bits/stdc++.h>
using namespace std;

int partitionNumber(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Cách duy nhất để phân hoạch số 0

    for (int i = 1; i <= n; i++)
    { // Xét từng số i từ 1 đến n
        for (int j = i; j <= n; j++)
        { // Cập nhật dp[j]
            dp[j] += dp[j - i];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Nhập số n: ";
    cin >> n;
    cout << "Số cách phân hoạch " << n << " là: " << partitionNumber(n) << endl;
    return 0;
}
