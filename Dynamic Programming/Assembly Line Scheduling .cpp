// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
    {
        // Code Here
        int n = a[0].size();
        T[0].push_back(1e9);
        T[1].push_back(1e9);

        int dp[2][n + 1];
        for (int j = n; j >= 0; j--)
        {
            for (int i = 0; i < 2; i++)
            {
                if (j == n)
                {
                    if (i == 0)
                        dp[i][j] = x[0];
                    else
                        dp[i][j] = x[1];
                }
                else
                {
                    if (i == 0)
                        dp[i][j] = a[i][j] + min(dp[i][j + 1], T[i][j + 1] + dp[i + 1][j + 1]);
                    else
                        dp[i][j] = a[i][j] + min(dp[i][j + 1], T[i][j + 1] + dp[i - 1][j + 1]);
                }
            }
        }
        return min(e[0] + dp[0][0], e[1] + dp[1][0]);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n)), T(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> T[i][j];
            }
        }
        vector<int> e(2), x(2);
        for (int i = 0; i < 2; i++)
        {
            cin >> e[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cin >> x[i];
        }

        Solution ob;
        int ans = ob.carAssembly(a, T, e, x);

        cout << ans << endl;
    }
} // } Driver Code Ends