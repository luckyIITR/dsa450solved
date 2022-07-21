//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // // Function to find the maximum number of cuts.
    // Tabulation dp
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;

            if (i - x >= 0)
                a = 1 + dp[i - x];
            if (i - y >= 0)
                b = 1 + dp[i - y];
            if (i - z >= 0)
                c = 1 + dp[i - z];
            dp[i] = max(a, max(b, c));
        }
        if (dp[n] < 0)
            return 0;
        else
            return dp[n];
    }

    // Recurrsion with memoization
    // int solve(int n, int x, int y, int z, vector<int> &dp)
    // {
    //     if (n == 0)
    //         return 0;
    //     if (n < 0)
    //         return INT_MIN;
    //     if (dp[n] != -1)
    //         return dp[n];
    //     int a = INT_MIN, b = INT_MIN, c = INT_MIN;
    //     if (n - x >= 0)
    //         a = 1 + solve(n - x, x, y, z, dp);
    //     if (n - y >= 0)
    //         b = 1 + solve(n - y, x, y, z, dp);
    //     if (n - z >= 0)
    //         c = 1 + solve(n - z, x, y, z, dp);
    //     dp[n] = max(a, max(b, c));
    //     return dp[n];
    // }
    // int maximizeTheCuts(int n, int x, int y, int z)
    // {
    //     vector<int> dp(n + 1, -1);
    //     int ans = solve(n, x, y, z, dp);
    //     if (ans < 0)
    //         return 0;
    //     else
    //         return ans;
    // }

    // Self written recurrsion
    // int solve(int n, int x, int y, int z, int count)
    // {
    //     if (n == 0)
    //         return count;
    //     if (n < 0)
    //         return 0;
    //     int l1 = solve(n - x, x, y, z, count + 1);
    //     int l2 = solve(n - y, x, y, z, count + 1);
    //     int l3 = solve(n - z, x, y, z, count + 1);
    //     int maxi = max(l1, l2);
    //     maxi = max(maxi, l3);
    //     return maxi;
    // }
    // int maximizeTheCuts(int n, int x, int y, int z)
    // {
    //     return solve(n, x, y, z, 0);
    // }
};

//{ Driver Code Starts.
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
}
// } Driver Code Ends