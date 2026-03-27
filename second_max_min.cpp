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

MaxMin max_min(vector<int>& arr, int beginning, int end) {
    //base case
    if (beginning == end) {
        return {arr[beginning], arr[beginning], INT_MIN, INT_MAX};
    }

    //divide into sub problems
    int mid = (beginning + end) / 2;
    MaxMin res_left = max_min(arr, beginning, mid);
    MaxMin res_right = max_min(arr, mid + 1, end);

    //merging part
    int maximum = max(res_left.maximum, res_right.maximum);
    int secondMaximum = merge_second_value(
        res_left.maximum,
        res_right.maximum,
        res_left.secondMaximum,
        res_right.secondMaximum,
        true
    );
    int minimum = min(res_left.minimum, res_right.minimum);
    int secondMinimum = merge_second_value(
        res_left.minimum,
        res_right.minimum,
        res_left.secondMinimum,
        res_right.secondMinimum,
        false
    );

    return {maximum, minimum, secondMaximum, secondMinimum};
}

int merge_second_value(int leftValue, int rightValue, int leftSecondValue, int rightSecondValue, bool findMaximum) {
    if (findMaximum) {
        return max(min(leftValue, rightValue), max(leftSecondValue, rightSecondValue));
    }

    return min(max(leftValue, rightValue), min(leftSecondValue, rightSecondValue));
}