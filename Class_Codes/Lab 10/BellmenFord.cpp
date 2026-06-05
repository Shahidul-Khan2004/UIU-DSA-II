#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    int V, E;

    vector<vector<int>> edgeList;
    cout << "Enter vertex cnt" << endl;
    cin >> V;
    cout << "Enter edge cnt" << endl;
    cin >> E;
    cout << "Enter edge" << endl;
    for (int i = 0; i < E; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;

        edgeList.push_back({u, v, w});
    }

    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    int src;
    cout << "Enter source Node" << endl;
    cin >> src;

    dist[src] = 0;

    for (int i = 1; i <= V; i++)
    {

        for (auto edge : edgeList)
        {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v])
            {
                // relax

                if (i == V)
                {
                    cout << "negative cycle detcted" << endl;
                    break;
                }

                dist[v] = dist[u] + w;
            }
        }
    }

    cout << " shortest distance: " << endl;

    for (int i = 0; i < V; i++)
    {

        cout << src << "to " << i << " " << dist[i] << endl;
    }
}