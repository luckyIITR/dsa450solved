#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // dp solution ---> .. TLE, because of finding max inside loop
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n];
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int maxi = INT_MIN;
            for (int j = 1; j <= k and (i + j) < n; j++)
            {
                maxi = max(maxi, dp[i + j]);
            }
            dp[i] = nums[i] + maxi;
        }
        return dp[0];
    }

    //  Instead use priority queue inside loop to get maximum. (solution accepted)
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        int dp[n];
        dp[n - 1] = nums[n - 1];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[n - 1], n - 1});
        for (int i = n - 2; i >= 0; i--)
        {
            while (pq.top().second - i > k)
            {
                pq.pop();
            }
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
