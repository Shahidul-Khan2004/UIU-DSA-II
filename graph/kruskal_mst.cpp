#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int> &parent);
void Union(int u, int v, vector<int> &parent, vector<int> &rank);

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    // Use V+1 size to safely support 1-based vertex indices
    vector<int> parent(V + 1, -1);
    vector<int> rank(V + 1, 1);

    int cost = 0, count = 0;

    for (vector<int> edge : edges)
    {
        int w = edge[0], u = edge[1], v = edge[2];
        if (find(u, parent) != find(v, parent))
        {
            cout << u << "--" << w << "--" << v << endl;
            Union(u, v, parent, rank);
            cost += w;
            count++;
        }
        if (count == V - 1)
            break;
    }
    cout << cost << endl;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU == rootV)
        return;

    if (rank[rootU] >= rank[rootV])
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
    else
    {
        parent[rootU] = rootV;
        rank[rootV]++;
    }
}