#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> max_min (vector<int> &arr, int beginning, int end);

int main () {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33};
    pair<int, int> res = max_min(arr, 0, arr.size() - 1);
    cout << "max: " << res.first << " min: " << res.second << endl;
}

pair<int, int> max_min (vector<int> &arr, int beginning, int end) {
    if (beginning == end) return {arr[beginning], arr[beginning]};
    int mid = (beginning + end) / 2;
    pair <int, int> res_left = max_min(arr, beginning, mid);
    pair <int, int> res_right = max_min(arr, mid + 1, end);
    int maximum = max(res_left.first, res_right.first);
    int minimum = min(res_left.second, res_right.second);
    return {maximum, minimum};
}