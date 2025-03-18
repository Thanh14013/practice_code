#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray with sum not exceeding Q
pair<int, int> longestSubarrayNotExceedingSum(int arr[], int n, int Q)
{
    int start = 0, end = 0; // Current window
    int maxLen = 0;         // Length of longest valid subarray
    int bestStart = -1;     // Starting index of best subarray
    int currSum = 0;        // Sum of current window elements

    while (end < n)
    {
        // Expand the window by including current element
        currSum += arr[end];

        // If current sum exceeds Q, shrink window from left
        while (start <= end && currSum > Q)
        {
            currSum -= arr[start];
            start++;
        }

        // Update the longest subarray if current is longer
        int currentLen = end - start + 1;
        if (currentLen > maxLen)
        {
            maxLen = currentLen;
            bestStart = start;
        }

        // Move window to right
        end++;
    }

    if (bestStart == -1)
    {
        // No valid subarray found
        return {-1, -1};
    }

    return {bestStart, bestStart + maxLen - 1};
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int Q;
    cout << "Enter the maximum sum allowed (Q): ";
    cin >> Q;

    pair<int, int> result = longestSubarrayNotExceedingSum(arr, n, Q);

    if (result.first == -1)
    {
        cout << "No subarray found with sum not exceeding " << Q << endl;
    }
    else
    {
        cout << "Longest subarray with sum not exceeding " << Q << " is from index "
             << result.first << " to " << result.second << endl;

        cout << "Subarray elements: ";
        for (int i = result.first; i <= result.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        int sum = 0;
        for (int i = result.first; i <= result.second; i++)
        {
            sum += arr[i];
        }
        cout << "Sum of subarray: " << sum << endl;
        cout << "Length of subarray: " << (result.second - result.first + 1) << endl;
    }

    return 0;
}