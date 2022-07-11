// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // dp
    int nCr(int n, int r)
    {
        int mod = 1e9 + 7;
        int dp[n + 1][r + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < r + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    if (j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
        return dp[n][r];
    }

    // Recurrsion
    int binomialCoeff(int n, int k)
    {
        // Base Cases
        if (k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;

        // Recur
        return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
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
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends