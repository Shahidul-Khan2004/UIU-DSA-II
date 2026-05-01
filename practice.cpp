#include <iostream>
#include <vector>

using namespace std;

int countEven(vector<int> &arr, int s, int e);

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 5, 6, 8, 9, 22};
    cout << countEven(arr, 0, arr.size() - 1) << endl;
}

int countEven(vector<int> &arr, int s, int e) {
    if(s == e) return !(arr[s] % 2);
    int mid = (s + e) / 2;
    int l = countEven(arr, s, mid);
    int r = countEven(arr, mid + 1, e);
    return l + r;
}