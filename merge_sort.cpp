#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void merge_sort(vector<int> &arr, int start, int end);
void merge(vector<int> &arr, int start, int mid, int end);

int main()
{
    vector<int> arr = {14, 15, -1, 4, 10, 2};
    int n = arr.size();

    merge_sort(arr, 0, n - 1);

    for (int x : arr) cout << x << endl;
}

void merge_sort(vector<int> &arr, int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> merged_arr;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            merged_arr.push_back(arr[i]);
            i++;
        }
        else {
            merged_arr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        merged_arr.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        merged_arr.push_back(arr[j]);
        j++;
    }
    for (int i = start, j = 0; i <= end; i++, j++) arr[i] = merged_arr[j];
}