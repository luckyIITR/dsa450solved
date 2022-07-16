// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Dp
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];

        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (j == m - 1)
                    dp[i][j] = M[i][j];
                else
                {
                    int s1 = -1 * 1e9, s2 = -1 * 1e9;
                    if (i - 1 >= 0)
                        s1 = dp[i - 1][j + 1];
                    if (i + 1 <= n - 1)
                        s2 = dp[i + 1][j + 1];
                    int res = max(s1, dp[i][j + 1]);
                    res = max(res, s2);
                    dp[i][j] = M[i][j] + res;
                }
            }
        }
        int maxii = -1 * 1e9;
        for (int i = 0; i < n; i++)
        {
            maxii = max(maxii, dp[i][0]);
        }

        return maxii;
    }

    // Recurrsion
    int solve(int n, int m, vector<vector<int>> M, int i, int j)
    {
        if (j == m - 1)
            return M[i][j];
        int s1 = -1 * 1e9, s2 = -1 * 1e9;
        if (i - 1 >= 0)
            s1 = solve(n, m, M, i - 1, j + 1);
        if (i + 1 <= n - 1)
            s2 = solve(n, m, M, i + 1, j + 1);
        int res = max(s1, solve(n, m, M, i, j + 1));
        res = max(res, s2);
        return res + M[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxi = -1 * 1e9;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, solve(n, m, M, i, 0));
        }

        return maxi;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends