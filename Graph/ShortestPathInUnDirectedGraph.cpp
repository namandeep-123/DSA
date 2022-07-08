#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<int> adj[])
{
    vector<int> dis(V + 1, INT_MAX);
    queue<int> q;

    dis[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (1 + dis[node] < dis[it])
            {
                dis[it] = 1 + dis[node];
                q.push(it);
            }
        }
    }

    return dis;
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
    vector<int> ans = shortestPath(n, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// 8 11
// 0 1
// 0 3
// 1 3
// 1 2
// 3 4
// 2 6
// 4 5
// 5 6
// 6 7
// 6 8
// 7 8