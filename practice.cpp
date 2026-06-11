#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX / 2);
    dist[src] = 0;
    for(int i = 0; i <= V-1; i++) {
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[v] > dist[u] + w) {
                if(i == V-1) {
                    cout << "negative cycle detected" << endl;
                    break;
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << src << " to " << i << ": " << dist[i] << endl;
}