//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    //  Greedy ---> O(N)time , O(1) space, ... Accepted solution only
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (n == 1)
            return 0;
        if (arr[0] == 0 and n > 1)
            return -1;

        int max_reachable = arr[0];
        int jump = 1;
        int step = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                break;
            step--;
            max_reachable = max(max_reachable, i + arr[i]);

            if (step == 0)
            {
                if (max_reachable <= i)
                    return -1;
                jump++;
                step = max_reachable - i;
            }
        }
        return jump;
    }

    //  Recurrsion
    int solve(int arr[], int start, int n)
    {
        if (start == n - 1)
        {
            return 0;
        }
        int ans = INT_MAX - 10;
        for (int step = 1; step <= min(n, arr[start]); step++)
        {
            int get_ans = solve(arr, start + step, n);
            if (get_ans == INT_MAX - 10)
                return -1;
            ans = min(ans, get_ans + 1);
        }
        return ans;
    }

    int minJumps(int arr[], int n)
    {
        // Your code here
        if (arr[0] == 0 and n > 1)
            return -1;

        return solve(arr, 0, n);
    }

    // Dp ---> O(N^2) time, O(N) space

    int minJumps(int arr[], int n)
    {
        int dp[n];
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int mini = INT_MAX - 10;
            for (int step = 1; step <= arr[i] && (i + step) < n; step++)
            {
                mini = min(mini, dp[i + step]);
            }
            dp[i] = mini + 1;
        }
        // for (int i = 0; i < n; i++)
        // {
        // 	cout << dp[i] << " ";
        // }
        // cout << endl;

        if (dp[0] == INT_MAX - 9)
            return -1;
        return dp[0];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends