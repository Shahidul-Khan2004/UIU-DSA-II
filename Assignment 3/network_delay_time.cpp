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