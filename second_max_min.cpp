#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct MaxMin
{
    int maximum;
    int minimum;
    int secondMaximum;
    int secondMinimum;
};

int merge_second_value(int leftValue, int rightValue, int leftSecondValue, int rightSecondValue, bool findMaximum);

MaxMin max_min(vector<int>& arr, int beginning, int end);

int main () {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33, -53};
    MaxMin res = max_min(arr, 0, arr.size() - 1);
    cout << "max: " << res.maximum << " min: " << res.minimum << endl;
    cout << "2nd max: " << res.secondMaximum << " 2nd min: " << res.secondMinimum << endl;
}

int merge_second_value(int leftValue, int rightValue, int leftSecondValue, int rightSecondValue, bool findMaximum) {
    if (findMaximum) {
        return max(min(leftValue, rightValue), max(leftSecondValue, rightSecondValue));
    }

    return min(max(leftValue, rightValue), min(leftSecondValue, rightSecondValue));
}

MaxMin max_min(vector<int>& arr, int beginning, int end) {
    if (beginning == end) {
        return {arr[beginning], arr[beginning], INT_MIN, INT_MAX};
    }

    int mid = (beginning + end) / 2;
    MaxMin left = max_min(arr, beginning, mid);
    MaxMin right = max_min(arr, mid + 1, end);

    MaxMin res;

    // maximum
    if (left.maximum > right.maximum) {
        res.maximum = left.maximum;
        res.secondMaximum = max(right.maximum, left.secondMaximum);
    } else {
        res.maximum = right.maximum;
        res.secondMaximum = max(left.maximum, right.secondMaximum);
    }

    // minimum
    if (left.minimum < right.minimum) {
        res.minimum = left.minimum;
        res.secondMinimum = min(right.minimum, left.secondMinimum);
    } else {
        res.minimum = right.minimum;
        res.secondMinimum = min(left.minimum, right.secondMinimum);
    }

    return res;
}