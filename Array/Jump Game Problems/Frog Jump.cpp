#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // bfs ... tle
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        queue<pair<int, int>> que;
        map<int, bool> mp;
        for (int i = 0; i < n; i++)
        {
            mp[stones[i]] = true;
        }
        que.push({stones[0], 0});
        while (!que.empty())
        {
            pair<int, int> node = que.front();
            que.pop();

            if (node.first == stones[n - 1])
                return true;

            int k = node.second;
            if (k - 1 > 0 and mp[node.first + k - 1])
                que.push({node.first + k - 1, k - 1});
            if (k > 0 and mp[node.first + k])
                que.push({node.first + k, k});
            if (mp[node.first + k + 1])
                que.push({node.first + k + 1, k + 1});
        }
        return false;
    }
};

class Solution
{
public:
    // dp solution (accepted)
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();

        map<int, vector<int>> mp; // to store -> how many different previous k is possible to reach stone value (stone[i])

        map<int, bool> stone_map; // simple stone values mapping (searching purpose)
        for (int i = 0; i < n; i++)
        {
            stone_map[stones[i]] = true;
        }

        mp[stones[0]].push_back(0); // k=0 assigned for stone[0]

        for (int i = 0; i < n; i++)
        {
            int m = mp[stones[i]].size();
            set<int> S; // generating all k's for next jump
            for (int j = 0; j < m; j++)
            {
                int k = mp[stones[i]][j];
                if (k - 1 > 0)
                    S.insert(k - 1);
                if (k > 0)
                    S.insert(k);
                S.insert(k + 1);
            }

            for (int k : S)
            {
                // standing at stones[i] check all the jump possible from here. and store prev k values for next stones
                if (stone_map[stones[i] + k] == true)
                    mp[stones[i] + k].push_back(k);
            }
        }
        if (mp[stones[n - 1]].size() != 0)
            return true;
        return false;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
