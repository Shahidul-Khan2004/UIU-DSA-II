// Dijkstra (takes 95ms)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto time: times) {
            int u = time[0], v = time[1], w = time[2];
            adjList[u-1].push_back({w, v-1});
        }
        vector<int> visited(n, 0);
        vector<int> dist(n, INT_MAX/2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k - 1] = 0;
        pq.push({dist[k - 1], k-1});
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
        sort(dist.begin(), dist.end());
        if (dist[n - 1] == INT_MAX / 2) return - 1;
        else return dist[n - 1];
    }
};

// bellmen ford (takes 955ms)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX / 2);
        dist[k-1] = 0;
        for(int i = 1; i < n; i++) {
            for(auto time: times) {
                int u = time[0], v = time[1], w = time[2];
                if(dist[u-1] + w < dist[v-1]) {
                    dist[v-1] = dist[u-1] + w;
                }
            }
        }
        sort(dist.begin(), dist.end());
        if (dist[n - 1] == INT_MAX / 2) return - 1;
        else return dist[n - 1];
    }
};