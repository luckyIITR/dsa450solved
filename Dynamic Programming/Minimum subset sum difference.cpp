// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        int arr_sum = sum;
        sum = sum / 2;
        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 or j == 0)
                    if (j == 0)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;

                else
                {
                    if (arr[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        for (int i = sum; i >= 0; i--)
        {
            if (dp[n][i])
                return arr_sum - 2 * i;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends