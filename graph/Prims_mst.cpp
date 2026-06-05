#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prims(vector<vector<pair<int, int>>> &adjList);

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
    cout << "Min cost: " << prims(adjList) << endl;
}

int prims(vector<vector<pair<int, int>>> &adjList) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int V = adjList.size();
    vector<int> visited(V, 0);
    pq.push({0, 0}); // distance, node
    int cost = 0;
    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        int w = node.first;
        int v = node.second;
        pq.pop();
        if(!visited[v]) {
            visited[v] = 1;
            cost += w;
            for(auto adj: adjList[v]) 
                pq.push({adj.first, adj.second});
        }
    }
    return cost;
}