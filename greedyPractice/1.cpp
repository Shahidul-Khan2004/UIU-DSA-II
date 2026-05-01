#include <iostream>
#include <vector>
#include <algorithm>

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
    cout << A[M - 1] - A[0] << endl;
}