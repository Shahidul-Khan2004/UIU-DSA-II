#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> coins = {1, 2, 5, 10, 25};
    int amount = 63;
    sort(coins.begin(), coins.end(), greater<int>());
    int count = 0;
    for (int coin: coins) {
        while(coin <= amount) {
            amount -= coin;
            count++;
            cout << coin << endl;
        }
    }
    cout << "total coins: " << count << endl;
}