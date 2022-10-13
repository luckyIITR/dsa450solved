#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // bfs solution .., not accepted (TLE)
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        if (s[n - 1] == '1')
            return false;
        queue<int> que;
        que.push(0);

        while (!que.empty())
        {
            int idx = que.front();
            if (idx == n - 1)
                return true;
            que.pop();

            for (int i = min(idx + maxJump, n - 1); i >= idx + minJump; i--)
            {
                if (s[i] == '0')
                    que.push(i);
            }
        }
        return false;
    }

    //  sliding window concept, accpeted solution
    bool canReach(string s, int minJump, int maxJump)
    {
        // sliding window concept
        int n = s.size();
        if (s[n - 1] == '1')
            return false;
        int start = 0, end = 0;

        bool dp[n]; // it will store whether ith pos is reachable or not
        dp[0] = true;

        // pos i = 1 to minJump is not reachable
        for (int i = 1; i < minJump; i++)
            dp[i] = false;

        int reachable_zero = 1; // starting index is zero
        for (int i = minJump; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (reachable_zero > 0)
                    dp[i] = true;
                else
                    dp[i] = false;
            }
            else
            {
                dp[i] = false;
            }

            if (dp[end + 1])
                reachable_zero++;
            end++;

            // not to slide the starting pointer till it reaches the maxJump
            if (i >= maxJump)
            {
                if (dp[start])
                    reachable_zero--;
                start++;
            }
        }
        return dp[n - 1];
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
