#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N; cin >> N;
    int C; cin >> C;
    vector<double> P;
    for (int i = 0; i < N; i++) {
        double tmp; cin >> tmp;
        P.push_back(tmp);
    }
    sort(P.begin(), P.end(), greater<double>());
    for (int i = 0; i < C; i++) P[i] *= 0.7;
    double total = 0;
    for (double p: P) total += p;
    cout << total << endl;
}