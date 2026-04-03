#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void quickSort(vector<int> &arr, int start, int end);
int partition(vector<int> &arr, int start, int end);

int main()
{
    srand(time(0));

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size() - 1);

    int k;
    cin >> k;
    cout << arr[k - 1] << endl;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int partition(vector<int> &arr, int start, int end) {
    int p_idx = start + rand() % (end - start + 1);
    swap(arr[p_idx], arr[end]);
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[end], arr[i + 1]);
    return i + 1;
}