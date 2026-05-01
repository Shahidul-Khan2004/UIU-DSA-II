#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int s, int e);
int partition(vector<int> &arr, int s, int e);

int main() {
    vector<int> arr = {5, 6, 4, 8, 7, 10, 9};
    quickSort(arr, 0, arr.size() - 1);
    for (int i: arr) cout << i << " ";
    cout << endl;
}

void quickSort(vector<int> &arr, int s, int e) {
    if (s >= e) return;
    int pivot_idx = partition(arr, s, e);
    quickSort(arr, s, pivot_idx - 1);
    quickSort(arr, pivot_idx + 1, e);
}

int partition(vector<int> &arr, int s, int e) {
    int i = s - 1;
    int pivot = arr[e];
    for(int j = s; j < e; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i + 1;
}