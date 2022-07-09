// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // DP
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    if (j == 0)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {

                    if (arr[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }

    // recurrsion
    bool solve(vector<int> arr, int sum, int n)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (arr[n - 1] > sum)
            return solve(arr, sum, n - 1);
        else
            return solve(arr, sum - arr[n - 1], n - 1) or solve(arr, sum, n - 1);
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        return solve(arr, sum, arr.size());
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
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends