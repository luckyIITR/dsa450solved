
// Simple Recurrsion (TLE) using count++
class Solution
{
public:
    void solve(int &count, int i, int j, int m, int n)
    {
        if (i >= m or j >= n)
            return;
        if ((i == m - 1) && (j == n - 1))
        {
            count++;
            return;
        }
        solve(count, i + 1, j, m, n);
        solve(count, i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        int count = 0;
        solve(count, 0, 0, m, n);
        return count;
    }
};

// counting different path and reporting to the boss
class Solution
{
public:
    int solve(int i, int j, int m, int n)
    {
        if (i == m - 1 and j == n - 1)
            return 1;
        if (i >= m or j >= n)
            return 0;
        return solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return solve(0, 0, m, n);
    }
};

// dp, in topological order, accepted in leet code
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};