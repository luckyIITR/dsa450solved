// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    int add(int a, int b) { return (a % mod + b % mod) % mod; }
    int multi(int a, int b) { return ((a % mod) * 1LL * (b % mod)) % mod; }
    int countFriendsPairings(int n)
    {
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = add(dp[i - 1], multi(dp[i - 2], i - 1));
        }
        return dp[n];
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends