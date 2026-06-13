class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void makeUnion(int x, int y) {
        int xPar = find(x);
        int yPar = find(y);

        if (xPar == yPar)
            return;

        if (rank[xPar] < rank[yPar]) {
            parent[xPar] = yPar;
        }
        else if (rank[xPar] > rank[yPar]) {
            parent[yPar] = xPar;
        }
        else {
            parent[yPar] = xPar;
            rank[xPar]++;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &road : roads) {
            makeUnion(road[0], road[1]);
        }

        int root1 = find(1);
        int ans = INT_MAX;

        for (auto &road : roads) {
            if (find(road[0]) == root1) {
                ans = min(ans, road[2]);
            }
        }

        return ans;
    }
};