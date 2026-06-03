class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        vector<int> durations = {1, 7, 30};
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MAX;
            int j = i;
            for (int cost = 0, duration = 0; cost < 3; cost++, duration++) {
                while (j < n && days[j] < days[i] + durations[duration])
                    j++;
                dp[i] = min(dp[i], dp[j] + costs[cost]);
            }
        }
        return dp[0];
    }
};