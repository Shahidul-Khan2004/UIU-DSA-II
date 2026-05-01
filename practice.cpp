#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &arr, int s, int e);
void merge(vector<int> &arr, int s, int mid, int e);

int main() {
    vector<int> arr = {14, 15, -1, 4, 10, 2};
    merge_sort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge_sort(vector<int> &arr, int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, mid, e);
}

void merge(vector<int> &arr, int s, int mid, int e) {
    int i = s;
    int j = mid + 1;
    vector<int> mArr;
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            mArr.push_back(arr[i]);
            i++;
        }
        else {
            mArr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        mArr.push_back(arr[i]);
        i++;
    }
    while (j <= e) {
        mArr.push_back(arr[j]);
        j++;
    }
    for(int i = s, j = 0; i <= e; i++, j++) arr[i] = mArr[j];
}