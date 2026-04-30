/* Jarif got stuck on an island. There is only one shop on this island, and it is open on all
days of the week except for Sunday. Consider following constraints: ​

N – The maximum unit of food you can buy each day. ​

S – Number of days you are required to survive. ​

M – Unit of food required each day to survive. ​

Currently, it’s Monday, and he needs to survive for the next ‘S’ days. ​

Find the minimum number of days on which you need to buy food from the shop so that
he can survive the next ‘S’ days or determine that it isn’t possible to survive. ​

Example 1: ​

Input: N = 16, S = 10, M = 2 ​

Output: 2 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int S, N, M;
    cout << "The maximum unit of food you can buy each day: "; cin >> N;
    cout << "Number of days you are required to survive: "; cin >> S;
    cout << "Unit of food required each day to survive: "; cin >> M;

    int min_days_to_visit_shop = ceil((double)(S * M) / N);
    int full_weeks = S / 7;
    int remaining_week = S % 7;
    int total_shop_open_days = full_weeks * 6 + remaining_week;
    if (min_days_to_visit_shop <= total_shop_open_days) cout << min_days_to_visit_shop << endl;
    else cout << "impossible to survive" << endl;
}