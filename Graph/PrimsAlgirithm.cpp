#include <bits/stdc++.h>
using namespace std;

vector<int> Prims(int V, vector<pair<int, int>> adj[])
{
    vector<int> key(V + 1, INT_MAX), parent(V + 1, -1);
    vector<int> mst(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < V; i++)
    {
        int u = pq.top().second;
        // We can also use for loop and iterate through to find min key which has not marked true as mst but time complexity get o(N * N)
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }
    return parent;
}

int main()
{
    int n, m, src;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> ans = Prims(n, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

// 4 6
// 0 1 2
// 1 2 3
// 2 4 7
// 1 4 5
// 1 3 8
// 0 3 6