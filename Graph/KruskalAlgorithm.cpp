#include <bits/stdc++.h>
using namespace std;

struct node
{
public:
    int u;
    int v;
    int wt;
    node(int first, int second, int third)
    {
        u = first;
        v = second;
        wt = third;
    }
};

int findPar(int u, vector<int> parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

void unionn(int ui, int vi, vector<int> &parent, vector<int> &rank)
{
    int u = findPar(ui, parent);
    int v = findPar(vi, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    vector<int> rank(n + 1, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;

    for (auto it : mst)
        cout << it.first << '-' << it.second << endl;
}