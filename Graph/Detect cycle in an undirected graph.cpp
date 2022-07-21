//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // DFS
    bool dfs(int V, vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (visited.find(neighbour) == visited.end())
            {
                bool check = dfs(V, adj, visited, neighbour, node);
                if (check)
                    return true;
            }
            else if (neighbour != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {

        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (visited.find(i) == visited.end())
            {
                bool cycle = dfs(V, adj, visited, i, -1);
                if (cycle)
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    // BFS
    bool isCycle(int V, vector<int> adj[])
    {
        unordered_map<int, bool> mp;
        for (int j = 0; j < V; j++)
        {
            if (mp.find(j) == mp.end())
            {
                queue<int> que;
                map<int, int> parent_arr;
                que.push(j);
                mp[j] = true;
                while (!que.empty())
                {
                    int front_node = que.front();
                    que.pop();

                    for (int i = 0; i < adj[front_node].size(); i++)
                    {
                        // cout << "adj[front_node][i] : " << adj[front_node][i] << endl;
                        if (mp.find(adj[front_node][i]) == mp.end())
                        {
                            parent_arr[adj[front_node][i]] = front_node;
                            mp[adj[front_node][i]] = true;
                            que.push(adj[front_node][i]);
                        }
                        else if (parent_arr[front_node] != adj[front_node][i])
                        {
                            // cout << "front_node" << front_node << " " << adj[front_node][i] << endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
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
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends