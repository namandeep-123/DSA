#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, vector<int> &vis, vector<int> adj[])
{

    queue<pair<int, int>> q;
    vis[node] = 1;
    q.push({node, -1});

    while (!q.empty())
    {
        int n = q.front().first;
        int prev = q.front().second;
        q.pop();

        for (auto i : adj[n])
        {
            if (!vis[i])
            {
                q.push({i, n});
                vis[i] = 1;
            }
            else if (prev != i)
                return true;
        }
    }

    return false;
}

bool BFS(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, vis, adj))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << BFS(n, adj);
}