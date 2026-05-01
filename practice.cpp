#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> max_min(vector<int> &arr, int s, int e);

int main() {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33};
    pair<int, int> m = max_min(arr, 0, arr.size() - 1);
    cout << "max: " << m.first << " min: " << m.second << endl;
}

pair<int, int> max_min(vector<int> &arr, int s, int e) {
    if (s == e) return {arr[s], arr[s]};
    int mid = (s + e) / 2;
    pair<int, int> l = max_min(arr, s, mid);
    pair<int, int> r = max_min(arr, mid + 1, e);
    int maximum = max(l.first, r.first);
    int minimum = min(l.second, r.second);
    return {maximum, minimum};
}