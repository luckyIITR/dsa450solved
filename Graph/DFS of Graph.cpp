//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(int V, vector<int> adj[], unordered_map<int, bool> &mp, int node, vector<int> &dfs)
    {
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (mp.find(adj[node][i]) == mp.end())
            {
                mp[adj[node][i]] = true;
                dfs.push_back(adj[node][i]);
                solve(V, adj, mp, adj[node][i], dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs{0};
        unordered_map<int, bool> mp;
        for (int i = 0; i < V; i++)
        {
            if (mp.find(i) == mp.end())
            {
                mp[i] = true;
                solve(V, adj, mp, 0, dfs);
            }
        }

        return dfs;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends