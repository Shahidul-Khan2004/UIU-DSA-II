#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maximum_subarray_sum(vector<int> &arr, int start, int end);
int cross_sum(vector<int> &arr, int start, int mid, int end);

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int n = arr.size() - 1;
    int res = maximum_subarray_sum(arr, 0, n);
    cout << res << endl;
}

int maximum_subarray_sum(vector<int> &arr, int start, int end) {
    if (start == end) return arr[start];
    int mid = (start + end) / 2;
    int l_sum = maximum_subarray_sum(arr, start, mid);
    int r_sum = maximum_subarray_sum(arr, mid + 1, end);
    int c_sum = cross_sum(arr, start, mid, end);

    return max(max(l_sum, r_sum), c_sum);
}

int cross_sum(vector<int> &arr, int start, int mid, int end) {
    int l_sum = INT_MIN;
    int r_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= start; i--) {
        sum += arr[i];
        l_sum = max(sum, l_sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        r_sum = max(sum, r_sum);
    }
    return l_sum + r_sum;
}