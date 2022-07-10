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
    int cutRod(int price[], int n)
    {
        int dp[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (i > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
                }
            }
        }
        return dp[n][n];
    }

    //  Recurrsin

    int solve(int price[], int al, int n)
    {
        //  Here n is acting like element of the lenght array
        if (al == 0 or n == 0)
            return 0;
        if (n > al)
            return solve(price, al, n - 1);
        else
            return max(price[n - 1] + solve(price, al - n, n), solve(price, al, n - 1));
    }
    int cutRod(int price[], int n)
    {
        return solve(price, n, n);
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

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends