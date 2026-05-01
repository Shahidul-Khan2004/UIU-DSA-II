#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximum_sub_sum(vector<int> &arr, int s, int e);
int cross_sum(vector<int> &arr, int s, int mid, int e);

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maximum_sub_sum(arr, 0, arr.size() - 1) << endl;
}

int maximum_sub_sum(vector<int> &arr, int s, int e) {
    if(s == e) return arr[s];
    int mid = (s + e) / 2;
    int l = maximum_sub_sum(arr, s, mid);
    int r = maximum_sub_sum(arr, mid + 1, e);
    int c = cross_sum(arr, s, mid, e);
    return max(max(l, r), c);
}

int cross_sum(vector<int> &arr, int s, int mid, int e) {
    int sum = 0;
    int l_sum = INT_MIN;
    int i = mid;
    while (i >= s) {
        sum += arr[i];
        if (sum >= l_sum) l_sum = sum;
        i--;
    }
    sum = 0;
    int r_sum = INT_MIN;
    int j = mid+1;
    while (j <= e) {
        sum += arr[j];
        if (sum >= r_sum) r_sum = sum;
        j++;
    }
    return l_sum + r_sum;
}