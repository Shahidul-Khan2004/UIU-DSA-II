#include <bits/stdc++.h>
using namespace std;

int main()
{

    int V, E;

    cout << "enter vertex count" << endl;
    cin >> V;

    cout << "enter edge count" << endl;
    cin >> E;

    // adjacency list

    // vectors of vectors of pairs

    vector<vector<pair<int, int>>> graph(V);

    // user input of edges

    for (int i = 0; i < E; i++)
    {

        int u, v, w; // src,dest,weight

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // as the graph is undirected
    }

    // find shortest path from source to all other nodes.

    int srcNode;
    cout << "Enter Source Node" << endl;

    cin >> srcNode;

    // visited to track visited nodes , distance to track the distance from source to other nodes

    int visited[V], dist[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX; // all distances are unknown
        visited[i] = -1;   // all node is unvisited
    }

    // declaring a min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

    dist[srcNode] = 0;

    // first visited node is source node itself

    que.push({dist[srcNode], srcNode}); // que -> {0,0}

    while (!que.empty())
    {

        // visit the closest node

        pair<int, int> visit = que.top(); // return the top element and as it is min heap, so the top node always has the minimum weight

        int u = visit.second;
        visited[u] = 1;
        que.pop();

        for (auto adj : graph[u])
        {
            int adjNode = adj.first;
            int weight = adj.second;

            if (visited[adjNode] != 1)
            {

                if (dist[adjNode] > dist[u] + weight)
                {
                    dist[adjNode] = dist[u] + weight;
                    que.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "src to" << i << ": inf" << endl;
        }
        cout << "src to" << i << ": " << dist[i] << endl;
    }
}