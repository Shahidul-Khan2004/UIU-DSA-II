#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Res
{
    int sum;
    int left_i;
    int right_i;
};

Res maximum_subarray_sum(vector<int> &nums, int start, int end);
Res cross_sum(vector<int> &nums, int start, int mid, int end);

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Res res = maximum_subarray_sum(nums, 0, nums.size() - 1);

    cout << "Sum = " << res.sum << endl;
    cout << "Start Index = " << res.left_i << endl;
    cout << "End Index = " << res.right_i << endl;
}

Res maximum_subarray_sum(vector<int> &nums, int start, int end)
{
    if (start == end)
        return {nums[start], start, end};
    int mid = (start + end) / 2;
    Res left = maximum_subarray_sum(nums, start, mid);
    Res right = maximum_subarray_sum(nums, mid + 1, end);
    Res cross = cross_sum(nums, start, mid, end);

    if (left.sum > right.sum)
    {
        return (left.sum > cross.sum) ? left : cross;
    }
    else
    {
        return (right.sum > cross.sum) ? right : cross;
    }
}

Res cross_sum(vector<int> &nums, int start, int mid, int end)
{
    int i = mid;
    int l_sum = INT_MIN;
    int l_idx = i;
    int sum = 0;
    while (i >= start)
    {
        sum += nums[i];
        if (l_sum < sum)
        {
            l_sum = sum;
            l_idx = i;
        }
        i--;
    }
    int j = mid + 1;
    int r_sum = INT_MIN;
    int r_idx = j;
    sum = 0;
    while (j <= end)
    {
        sum += nums[j];
        if (r_sum < sum)
        {
            r_sum = sum;
            r_idx = j;
        }
        j++;
    }
    return {r_sum + l_sum, l_idx, r_idx};
}