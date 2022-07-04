#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int src, vector<int> &color, vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto i : adj[node])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if (color[i] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool bipartite(int V, vector<int> adj[])
{
    vector<int> color(V + 1, -1);

    for (int i = 1; i <= V; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, color, adj))
                return false;
        }
    }

    return true;
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

    cout << bipartite(node, adj);
}

//         4   5   6
// 1 2 3               10 11
//         7       9
// 11 11
// 1 2
// 2 3
// 3 4
// 3 7
// 4 5
// 5 6
// 6 10
// 7 8
// 8 9
// 9 10
// 10 11