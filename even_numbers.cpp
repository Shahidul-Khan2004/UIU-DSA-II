#include <iostream>
#include <vector>

using namespace std;

int count_even(vector<int> &arr, int start, int end);

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 5, 6, 8, 9, 22};
    cout << count_even(arr, 0, arr.size() - 1) << endl;
}

int count_even(vector<int> &arr, int start, int end) {
    if (start == end) return !(arr[start] % 2);
    int mid = (start + end) / 2;
    int left = count_even(arr, start, mid);
    int right = count_even(arr, mid+1, end);
    return left + right;
}