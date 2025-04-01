#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    int min_sum = 9999;
    int sum = a[0];
    int left = 0;
    int right = 1;
    while (left <= right && right < n)
    {
        while (sum < k)
        {
            sum += a[right];
            right++;
        }
        while (sum >= k)
        {
            min_sum = min(min_sum, sum);
            sum -= a[left];
            left++;
        }
    }
    if (min_sum == 9999)
        cout << "Not possible";
    else
        cout << min_sum;
    return 0;
}