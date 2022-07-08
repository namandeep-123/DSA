#include <bits/stdc++.h>
using namespace std;
// Kahn's Algorithm
bool CycleDetection(int V, vector<int> adj[])
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

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node])
        {
            Indegree[it]--;
            if (Indegree[it] == 0)
                q.push(it);
        }
    }
    if (count == V)
        return false;
    return true;
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

    cout << CycleDetection(nodes, adj);
}