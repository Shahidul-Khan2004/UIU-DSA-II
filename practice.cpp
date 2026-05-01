#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class extreme {
    public:
    int max;
    int max2;
    int min;
    int min2;
};

extreme maxmin(vector<int> &arr, int s, int e);

int main() {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33, -53};
    extreme m = maxmin(arr, 0, arr.size() - 1);
    cout << m.max << " " << m.max2 << endl;
    cout << m.min << " " << m.min2 << endl;
}

extreme maxmin(vector<int> &arr, int s, int e) {
    if (s == e) return {arr[s], INT_MIN, arr[s], INT_MAX};
    int mid = (s + e) / 2;
    extreme l = maxmin(arr, s, mid);
    extreme r = maxmin(arr, mid + 1, e);
    extreme res;
    if (l.max > r.max) {
        res.max = l.max;
        (r.max > l.max2) ? res.max2 = r.max : res.max2 = l.max2;
    }
    else {
        res.max = r.max;
        (l.max > r.max2) ? res.max2 = l.max : res.max2 = r.max2;
    }

    if (l.min < r.min) {
        res.min = l.min;
        (l.min2 < r.min) ? res.min2 = l.min2 : res.min2 = r.min;
    }
    else {
        res.min = r.min;
        (r.min2 < l.min) ? res.min2 = r.min2 : res.min2 = l.min;
    }
    return res;
}