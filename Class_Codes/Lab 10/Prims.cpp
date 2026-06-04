#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    int V, E;

    cout << "Enter vertex cnt" << endl;
    cin >> V;
    cout << "Enter edge cnt" << endl;
    cin >> E;
    cout << "Enter edge" << endl;
    // adjacency list

    vector<vector<pair<int, int>>> adjList(V);

    for (int i = 0; i < E; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;

        // for undirected graph
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    //{dist,adjNode}
    pq.push({0, 0});
    int mincost = 0;
    while (!pq.empty())
    {

        pair<int, int> adjNode = pq.top();

        int wt = adjNode.first;
        int v = adjNode.second;
        pq.pop();

        if (visited[v] == 1)
        {
            continue;
        }

        mincost += wt;
        visited[v] = 1;

        for (auto adj : adjList[v])
        {

            pq.push({adj.second, adj.first});
        }
    }

    cout << "Minimum cost: " << mincost << endl;
}