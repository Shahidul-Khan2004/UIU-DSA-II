#include <iostream>
#include <vector>

using namespace std;

int majority(vector<int> &arr, int s, int e);

int main() {
    vector<int> arr = {2, 3, 1, 3, 3, 3, 2};
    int element = majority(arr, 0, arr.size() - 1);
    cout << element << endl;
}

int majority(vector<int> &arr, int s, int e) {
    if (s == e) return arr[s];
    int mid = (s + e) / 2;
    int l = majority(arr, s, mid);
    int r = majority(arr, mid + 1, e);
    if (l == r) return l;
    int lcount = 0; int rcount = 0;
    for(int i = s; i <= e; i++) {
        if (arr[i] == l) lcount++;
        else if (arr[i] == r) rcount++;
    }
    if (lcount > rcount) return l;
    else return r;
}