// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int M = 1000000007;
    int add(int a, int b) { return ((a % M + b % M) % M); }
    int multi(int a, int b) { return ((a % M) * 1LL * (b % M)) % M; }
    long long countWays(int n, int k)
    {
        long long dp[n + 1];
        dp[1] = k;
        dp[2] = k * k;
        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = multi(add(dp[i - 2], dp[i - 1]), k - 1);
        }
        return dp[n];
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
} // } Driver Code Ends