#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<pair<int, int>> adj[], int src)
{
  vector<int> dis(V + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, src});
  dis[1] = 0;
  while (!pq.empty())
  {
    int dist = pq.top().first;
    int prev = pq.top().second;
    pq.pop();

    for (auto it : adj[prev])
    {
      int next = it.first;
      int nextdis = it.second;

      if (dis[next] > dis[prev] + nextdis)
      {
        dis[next] = dis[prev] + nextdis;
        pq.push({dis[next], next});
      }
    }
  }
  return dis;
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
  cout << "source : ";
  cin >> src;
  vector<int> ans = shortestPath(n, adj, src);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}

// 5 6
// 1 2 2
// 2 5 5
// 1 4 1
// 4 3 3
// 2 3 4
// 3 5 1
// source = 1
