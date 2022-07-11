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
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N + 1][N + 1];
        for (int j = 1; j < N; j++)
        {
            for (int i = j; i > 0; i--)
            {
                if (i == j)
                    dp[i][j] = 0;
                else
                {
                    int temp = 1e9;
                    for (int k = i; k < j; k++)
                    {
                        temp = min(temp, dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                    }
                    dp[i][j] = temp;
                }
            }
        }
        return dp[1][N - 1];
    }

    // Recurrsion
    // int solve(int arr[], int L, int R)
    // {
    //     if (L == R)
    //         return 0;
    //     int cost_min = 1e9;
    //     for (int k = L; k < R; k++)
    //     {
    //         cost_min = min(cost_min, solve(arr, L, k) + solve(arr, k + 1, R) + arr[L - 1] * arr[k] * arr[R]);
    //     }
    //     return cost_min;
    // }

    // int matrixMultiplication(int N, int arr[])
    // {
    //     return solve(arr, 1, N - 1);
    // }
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends