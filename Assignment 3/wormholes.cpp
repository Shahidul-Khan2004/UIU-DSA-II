#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase) {
        testCase--;
        int V, E;
        cin >> V >> E;

        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        vector<int> dist(V, INT_MAX / 2);
        dist[0] = 0;  // Earth

        bool negativeCycle = false;

        for (int i = 1; i <= V; i++) {
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    if (i == V) {
                        negativeCycle = true;
                        break;
                    }
                    dist[v] = dist[u] + w;
                }
            }

            if (negativeCycle)
                break;
        }

        if (negativeCycle)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }

    return 0;
}