// most optimised solution (tabulation)

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {

                if (i > j)
                    continue;
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++)
                {
                    int coins = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    if (coins > maxi)
                        maxi = coins;
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

// recursion + memoisation

class Solution
{
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int coins = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp);
            if (coins > maxi)
                maxi = coins;
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(1, n, nums, dp);
    }
};

// backtracking soln(will not get accepted because of exponential time complexity ) and will not be able to memoise it as vector is varying (BRUTE FORCE)

class Solution
{
public:
    int maxprofit(int i, int j, vector<int> &nums)
    {

        if (i == j - 2)
            return nums[i + 1];

        int maxi = INT_MIN;
        for (int k = i + 1; k < j; k++)
        {

            int profit = nums[k - 1] * nums[k] * nums[k + 1];
            int x = nums[k];
            nums.erase(nums.begin() + k);
            profit += maxprofit(i, j - 1, nums);

            nums.insert(nums.begin() + k, x);

            maxi = max(maxi, profit);
        }

        return maxi;
    }
    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return maxprofit(0, n + 1, nums);
    }
};