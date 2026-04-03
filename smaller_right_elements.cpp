#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> countSmaller(vector<int> &arr);
void mergeSort(vector<pair<int, int>> &element_idx, int start, int end, vector<int> &count);
void merge(vector<pair<int, int>> &element_idx, int start, int mid, int end, vector<int> &count);

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);
    for (int num : ans)
        cout << num << " ";
    cout << endl;
}

vector<int> countSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> count(n, 0);
    vector<pair<int, int>> element_idx;
    for (int i = 0; i < n; i++)
        element_idx.push_back({arr[i], i});
    mergeSort(element_idx, 0, n - 1, count);
    return count;
}

void mergeSort(vector<pair<int, int>> &element_idx, int start, int end, vector<int> &count)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(element_idx, start, mid, count);
    mergeSort(element_idx, mid + 1, end, count);
    merge(element_idx, start, mid, end, count);
}

void merge(vector<pair<int, int>> &element_idx, int start, int mid, int end, vector<int> &count)
{
    int i = start;
    int j = mid + 1;
    int rightCount = 0;
    vector<pair<int, int>> tmp;
    while (i <= mid && j <= end)
    {
        if (element_idx[i].first >= element_idx[j].first)
        {
            rightCount++;
            tmp.push_back(element_idx[j]);
            j++;
        }
        else
        {
            count[element_idx[i].second] += rightCount;
            tmp.push_back(element_idx[i]);
            i++;
        }
    }
    while (i <= mid)
    {
        count[element_idx[i].second] += rightCount;
        tmp.push_back(element_idx[i]);
        i++;
    }
    while (j <= end)
    {
        tmp.push_back(element_idx[j]);
        j++;
    }
    for (int i = start, j = 0; i <= end; i++, j++)
        element_idx[i] = tmp[j];
}