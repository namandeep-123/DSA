#include <bits/stdc++.h>
using namespace std;

void topologicalDFS(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &s)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            topologicalDFS(it.first, vis, adj, s);
        }
    }
    s.push(node);
}

void shortestPath(int V, vector<pair<int, int>> adj[])
{
    stack<int> s;
    vector<int> vis(V + 1, 0);

    for (int i = 0; i <= V; i++)
    {
        if (!vis[i])
        {
            topologicalDFS(i, vis, adj, s);
        }
    }

    vector<int> dis(V + 1, INT_MAX);
    dis[0] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << "hi" << endl;
        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < dis.size(); i++)
    {
        cout << dis[i] << " ";
    }
}

int main()
{
    int node, edges;

    cin >> node >> edges;

    vector<pair<int, int>> adj[node + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    shortestPath(node, adj);
}

// 5 7
// 0 1 2
// 0 4 1
// 1 2 3
// 2 3 6
// 4 2 2
// 4 5 4
// 5 3 1