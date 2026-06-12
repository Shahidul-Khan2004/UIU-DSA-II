#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
    vector<int> coins = {3, 6, 5, 8};
    int sum = 20;
    int n = coins.size();

    vector<int> dp(sum + 1, INT_MAX/2);
    dp[0] = 0;

    for(int i = 1; i <= sum; i++) {
        for(int coin: coins) {
            if(coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    cout << dp[sum] << endl;

    return 0;
}