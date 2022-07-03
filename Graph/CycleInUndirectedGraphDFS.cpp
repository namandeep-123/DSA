#include <bits/stdc++.h>
using namespace std;

bool dfsCyclePossible(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {

            if (dfsCyclePossible(i, node, vis, adj))
            {
                return true;
            }
        }
        else if (parent != i)
        {
            return true;
        }
    }

    return false;
}

bool dfsCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (dfsCyclePossible(i, -1, vis, adj))
                return true;
        }
    }

    return false;
}

int main()
{
    int node, edges;
    cin >> node >> edges;

    vector<int> adj[node + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfsCycle(node, adj);
}