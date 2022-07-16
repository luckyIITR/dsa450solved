class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        target = abs(target);
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++)
            s += nums[i];
        int sum = (target + s) / 2;
        float check = (target + s) / 2.0;
        if (check != sum)
            return 0;
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {

                    if (nums[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};