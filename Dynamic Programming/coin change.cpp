class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    if (j == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 999999999;
                }
                else
                {
                    if (coins[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
            }
        }
        if (dp[n][amount] == 999999999)
            return -1;
        return dp[n][amount];
    }
};

// Coin change recurssion:
#include <iostream>
using namespace std;

int inf = 999999999;
int coin_change(int coins[], int amount, int n, int max_coin)
{
    if (amount == 0)
        return 0;
    if (n == 0)
        return inf;
    if (coins[n - 1] > amount)
        return coin_change(coins, amount, n - 1, max_coin);
    return min(1 + coin_change(coins, amount - coins[n - 1], n, max_coin), coin_change(coins, amount, n - 1, max_coin));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;
    cout << coin_change(coins, amount, n, n) << endl;
    return 0;
}
