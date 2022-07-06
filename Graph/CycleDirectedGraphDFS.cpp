#include <bits/stdc++.h>
using namespace std;

bool cycleDirectionDFS(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (cycleDirectionDFS(it, vis, dfsVis, adj))
                return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool cycleDirection(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    vector<int> dfsVis(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (cycleDirectionDFS(i, vis, dfsVis, adj))
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
    }

    cout << cycleDirection(node, adj);
}

// To check Cycle in Directed Graph
// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7