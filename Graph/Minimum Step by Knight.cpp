//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    bool isvaild(int n_x, int n_y, int N, vector<vector<int>> &visited)
    {
        if (n_x < N and n_x >= 0 and n_y < N and n_y >= 0 and visited[n_x][n_y] == 0)
            return true;
        return false;
    }

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        vector<vector<int>> visited(N, vector<int>(N, 0));
        int st_x = KnightPos[0] - 1;
        int st_y = KnightPos[1] - 1;
        int tgt_x = TargetPos[0] - 1;
        int tgt_y = TargetPos[1] - 1;
        if (st_x == tgt_x and st_y == tgt_y)
            return 0;
        visited[st_x][st_y] = true;
        queue<pair<int, int>> que;
        que.push({st_x, st_y});
        while (!que.empty())
        {
            int cur1 = que.size();
            pair<int, int> node = que.front();
            que.pop();
            int m_x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
            int m_y[] = {1, 2, 2, 1, -1, -2, -2, -1};
            for (int i = 0; i < 8; i++)
            {
                int n_x = node.first + m_x[i];
                int n_y = node.second + m_y[i];
                if (n_x == tgt_x and n_y == tgt_y)
                    return visited[node.first][node.second];
                if (isvaild(n_x, n_y, N, visited))
                {
                    visited[n_x][n_y] = visited[node.first][node.second] + 1;
                    que.push({n_x, n_y});
                }
            }
            int cur2 = que.size();
        }
        return visited[tgt_x][tgt_y];
    }
};

//{ Driver Code Starts.
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends