#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int memo[100][100];
int dp[100][100];

int coinChange(int coins[], int sum, int n)
{
    if (sum == 0)
    {
        return 0;
    }
    if (n == 0 && sum > 0)
    {
        return INT_MAX - 1;
    }

    if (memo[n][sum] != -1)
    {
        return memo[n][sum];
    }

    if (coins[n - 1] <= sum)
    {
        memo[n][sum] = min(1 + coinChange(coins, sum - coins[n - 1], n), coinChange(coins, sum, n - 1));
    }
    else
    {
        memo[n][sum] = coinChange(coins, sum, n - 1);
    }

    return memo[n][sum];
}

int coinChangeDp(int coins[], int sum, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;                    
            }
            else if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;          
            }
            else if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                {
                    dp[i][j] = j / coins[i - 1];
                }
                else
                {
                    dp[i][j] = INT_MAX - 1;
                }
            }
            else
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int coins[] = {3, 6, 5, 8};
    int sum = 20;
    int n = 4;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            memo[i][j] = -1;
        }
    }

    int resm = coinChange(coins, sum, n);
    cout << "Minimum number of coins required (memoization) = " << resm << endl;

    int rest = coinChangeDp(coins, sum, n);
    cout << "Minimum number of coins required (tabulation) = " << rest << endl;

    return 0;
}