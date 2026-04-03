#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &arr, int start, int end);
int countMajor(vector<int> &arr, int start, int end, int num);

int main()
{
    vector<int> arr = {2, 2, 1, 2, 3, 2, 2};
    int n = arr.size();

    cout << "Majority element: " << majorityElement(arr, 0, n - 1) << endl;

    return 0;
}

int majorityElement(vector<int> &arr, int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int leftMajor = majorityElement(arr, start, mid);
    int rightMajor = majorityElement(arr, mid + 1, end);

    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countMajor(arr, start, end, leftMajor);
    int rightCount = countMajor(arr, start, end, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int countMajor(vector<int> &arr, int start, int end, int num)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == num)
            count++;
    }
    return count;
}