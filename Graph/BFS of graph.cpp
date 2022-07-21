//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs{0};
        queue<int> que;
        unordered_map<int, bool> mp;
        que.push(0);
        mp[0] = true;
        while (!que.empty())
        {
            int front_node = que.front();
            que.pop();

            for (int i = 0; i < adj[front_node].size(); i++)
            {
                if (mp.find(adj[front_node][i]) == mp.end())
                {
                    mp[adj[front_node][i]] = true;
                    bfs.push_back(adj[front_node][i]);
                    que.push(adj[front_node][i]);
                }
            }
        }
        return bfs;
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends