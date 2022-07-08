#include <bits/stdc++.h>
using namespace std;
// Kahn's Algorithm

vector<int> topologicalSort(int V, vector<int> adj[])
{
    vector<int> Indegree(V + 1, 0);

    for (int i = 0; i <= V; i++)
    {
        for (auto it : adj[i])
        {
            Indegree[it]++;
        }
    }
    queue<int> q;

    for (int i = 0; i <= V; i++)
    {
        if (Indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            Indegree[it]--;
            if (Indegree[it] == 0)
                q.push(it);
        }
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