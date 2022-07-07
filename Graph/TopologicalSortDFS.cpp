#include <bits/stdc++.h>
using namespace std;

void topologicalSortDfs(int node, vector<int> vis, stack<int> &s, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            topologicalSortDfs(it, vis, s, adj);
    }

    s.push(node);
}

vector<int> topologicalSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            topologicalSortDfs(i, vis, s, adj);
        }
    }
    vector<int> topo;
    while (!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }

    return topo;
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
    }

    vector<int> ans = topologicalSort(nodes, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}