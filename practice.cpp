#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adjList(V);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }
    vector<int> visited(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int cost = 0;
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        int v = node.second;
        int w = node.first;
        pq.pop();
        if(!visited[v]) {
            visited[v] = 1;
            cost+=w;
            for(auto adj:adjList[v]) {
                pq.push({adj.first, adj.second});
            }
        }
    }
    cout << cost << endl;
}

