//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int V, vector<int> adj[], int node, unordered_map<int, bool> &visited, map<int, bool> &path)
    {
        visited[node] = true;
        path[node] = true;

        for (auto neighbour : adj[node])
        {
            if (visited.find(neighbour) == visited.end())
            {

                bool check = dfs(V, adj, neighbour, visited, path);
                if (check)
                    return true;
            }
            else if (path[neighbour] == true)
            {
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        map<int, bool> path;
        for (int i = 0; i < V; i++)
        {

            if (visited.find(i) == visited.end())
            {
                bool check = dfs(V, adj, i, visited, path);
                if (check)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends