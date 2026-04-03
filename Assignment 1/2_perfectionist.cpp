#include <iostream>
#include <vector>

using namespace std;

int countViolations(vector<int> &arr, int start, int end);
int mergeV(vector<int> &arr, int start, int mid, int end);

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1};

    cout << countViolations(arr, 0, arr.size() - 1) << endl;
}

int countViolations(vector<int> &arr, int start, int end)
{
    if (start == end)
        return 0;
    int mid = (start + end) / 2;
    int left = countViolations(arr, start, mid);
    int right = countViolations(arr, mid + 1, end);
    int cross = mergeV(arr, start, mid, end);

    return left + right + cross;
}

int mergeV(vector<int> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int countViolations = 0;
    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            countViolations += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = start, j = 0; i <= end; i++, j++)
        arr[i] = temp[j];
    return countViolations;
}