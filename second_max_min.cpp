#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

pair<pair<int, int>, pair<int, int>> max_min (vector<int> &arr, int beginning, int end);
int secondMax3(int first, int second, int third);
int secondMin3(int first, int second, int third);

int main () {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33, -53};
    pair<pair<int, int>, pair<int, int>> res = max_min(arr, 0, arr.size() - 1);
    cout << "max: " << res.first.first << " min: " << res.first.second << endl;
    cout << "2nd max: " << res.second.first << " 2nd min: " << res.second.second << endl;
}

pair<pair<int, int>, pair<int, int>> max_min (vector<int> &arr, int beginning, int end) {
    if (beginning == end) return {{arr[beginning], arr[beginning]}, {INT_MIN, INT_MAX}};
    int mid = (beginning + end) / 2;
    pair <pair<int, int>, pair<int, int>> res_left = max_min(arr, beginning, mid);
    pair <pair<int, int>, pair<int, int>> res_right = max_min(arr, mid + 1, end);
    int maximum = max(res_left.first.first, res_right.first.first);
    int secondMaximum = secondMax3(res_left.first.first, res_right.first.first, max(res_left.second.first, res_right.second.first));
    int minimum = min(res_left.first.second, res_right.first.second);
    int secondMinimum = secondMin3(res_left.first.second, res_right.first.second, min(res_left.second.second, res_right.second.second));
    return {{maximum, minimum}, {secondMaximum, secondMinimum}};
}

int secondMax3(int first, int second, int third) {
    int max = (first > second) ? first : second;
    int secondMax = (first < second) ? first : second;
    max = (max > third) ? max : third;
    secondMax = (secondMax < third && third < max) ? third : secondMax;
    return secondMax;
}

int secondMin3(int first, int second, int third) {
    int min = (first < second) ? first : second;
    int secondMin = (first > second) ? first : second;
    min = (min < third) ? min : third;
    secondMin = (third < secondMin && third > min) ? third : secondMin;
    return secondMin;
}