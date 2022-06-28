#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfsHelper(i, vis, adj, dfs);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[])
{
    vector<int> DFS;
    vector<int> vis(V + 1, 0); // visited Nodes;

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            dfsHelper(i, vis, adj, DFS);
        }
    }

    return DFS;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = dfs(nodes, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
