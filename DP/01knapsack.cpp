#include <iostream>
#include <vector>

using namespace std;

int knapSackDP(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if(wt[i] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i - 1][w - wt[i]] + val[i]);
            }
            else dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;

    cout << "=== 0/1 Knapsack - Memoized Recursion (1-BASED INDEXING) ===\n\n";

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n + 1), wt(n + 1);
    val[0] = 0;
    wt[0] = 0;

    cout << "Enter value of each item (item 1 to " << n << "): ";
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    cout << "Enter weight of each item (item 1 to " << n << "): ";
    for (int i = 1; i <= n; i++)
        cin >> wt[i];

    cout << "Enter knapsack capacity (W): ";
    cin >> W;

    int maxValueT = knapSackDP(W, wt, val, n);

    cout << "Maximum value that can be obtained = " << maxValueT << endl;

    return 0;
}