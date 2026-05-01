#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> countSmaller(vector<int> &arr);
void mergeSort(vector<pair<int, int>> &e_i, int s, int e, vector<int> &count);
void merge(vector<pair<int, int>> &e_i, int s, int mid, int e, vector<int> &count);

int main () {
    vector<int> arr = {5, 2, 6, 1};
    vector<int> res = countSmaller(arr);
    for(int r: res) cout << r << " ";
    cout << endl;
}

vector<int> countSmaller(vector<int> &arr) {
    vector<pair<int, int>> element_i; 
    for (int i = 0; i < arr.size(); i++) {
        element_i.push_back({arr[i], i});
    }
    vector<int> count(arr.size(), 0);
    mergeSort(element_i, 0, arr.size() - 1, count);
    return count;
}

void mergeSort(vector<pair<int, int>> &e_i, int s, int e, vector<int> &count) {
    if(s >= e) return;
    int mid = (s + e) / 2;
    mergeSort(e_i, s, mid, count);
    mergeSort(e_i, mid + 1, e, count);
    merge(e_i, s, mid, e, count);
}

void merge(vector<pair<int, int>> &e_i, int s, int mid, int e, vector<int> &count) {
    int i = s;
    int j = mid + 1;
    int right_count = 0;
    vector<pair<int, int>> tmp;
    while(i <= mid && j <= e) {
        if(e_i[j].first < e_i[i].first) {
            right_count++;
            tmp.push_back(e_i[j]);
            j++;
        }
        else {
            count[e_i[i].second] += right_count;
            tmp.push_back(e_i[i]);
            i++;
        }
    }
    while (i <= mid) {
        count[e_i[i].second] += right_count;
        tmp.push_back(e_i[i]);
        i++;
    }
    while (j <= e) {
        tmp.push_back(e_i[j]);
        j++;
    }
    for(int i = s, j = 0; i <= e; i++, j++) e_i[i] = tmp[j];
}