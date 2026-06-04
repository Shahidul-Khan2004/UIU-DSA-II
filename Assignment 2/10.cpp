#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int D;
    cin >> D;

    const int INF = INT_MAX / 2;

    vector<int> dp(M + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int sum = M; sum >= coin; sum--) {
            dp[sum] = min(dp[sum], dp[sum - coin] + 1);
        }
    }

    if (dp[M] <= D)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}