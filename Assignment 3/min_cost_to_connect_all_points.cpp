class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
                adjList[i].push_back({w, j});
                adjList[j].push_back({w, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        int cost = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            pair<int, int> node = pq.top();
            int w = node.first;
            int v = node.second;
            pq.pop();
            if(!visited[v]) {
                visited[v] = 1;
                cost += w;
                for(auto adj: adjList[v]) pq.push({adj.first, adj.second});
            }
        }
        return cost;
    }
};