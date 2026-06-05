#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adjList(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }
    int src;
    cin >> src;

    // algo
    vector<int> visited(V, 0);
    vector<int> dist(V, INT_MAX / 2);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        int u = node.second;
        visited[u] = 1;
        pq.pop();
        for(auto adj: adjList[u]) {
            int w = adj.first;
            int v = adj.second;
            if(!visited[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print distance
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX / 2)
        {
            cout << "src to " << i << ": inf" << endl;
        }
        cout << "src to " << i << ": " << dist[i] << endl;
    }
}