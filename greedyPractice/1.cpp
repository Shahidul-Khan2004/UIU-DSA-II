#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N; cin >> N;
    int M; cin >> M;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }
    sort(A.begin(), A.end());
    int ans = INT_MAX;

    for (int i = 0; i <= N - M; i++) {
        int diff = A[i + M - 1] - A[i];
        ans = min(ans, diff);
    }

    cout << ans << endl;
}