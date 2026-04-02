#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int start, int end);
int partition(vector<int> &arr, int start, int end);

int main()
{
    vector<int> arr = {5, 6, 4, 8, 7, 10, 9};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}