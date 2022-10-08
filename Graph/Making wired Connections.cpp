class Solution
{
public:
    void dfs(vector<int> g[], vector<bool> &visited, int node)
    {
        visited[node] = true;
        for (int i = 0; i < g[node].size(); i++)
        {
            if (visited[g[node][i]] == false)
                dfs(g, visited, g[node][i]);
        }
    }
    void bfs(vector<int> g[], vector<bool> &visited, int node)
    {
        queue<int> que;
        que.push(node);
        visited[node] = true;
        while (!que.empty())
        {
            int front_node = que.front();
            que.pop();
            for (auto neighbour : g[front_node])
            {
                if (visited[neighbour] == false)
                {
                    visited[neighbour] = true;
                    que.push(neighbour);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int no_e = connections.size();
        if (no_e < n - 1)
            return -1;
        vector<int> g[n];
        for (int i = 0; i < no_e; i++)
        {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        int comp = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                bfs(g, visited, i);
                comp++;
            }
        }
        return comp - 1;
    }
};