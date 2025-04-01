#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    vector<int> dp(n);
    dp[0] = 1;
    set<char> st;
    st.insert(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.find(s[i]) != st.end())
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
            st.insert(s[i]);
        }
    }
    cout << dp[n - 1];
    return 0;
}