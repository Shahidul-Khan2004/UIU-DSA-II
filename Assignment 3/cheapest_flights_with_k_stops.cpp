class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX/2);
        dist[src] = 0;
        for (int i = 1; i <= k + 1; i++) {
            vector<int> tmp = dist;
            for (auto flight: flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if(tmp[v] > dist[u] + w) {
                    tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX / 2 ? -1 : dist[dst];
    }
};