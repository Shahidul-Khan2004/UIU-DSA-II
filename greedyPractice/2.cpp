#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    vector<int> requirements = {15000, 25000};
    vector<int> values = {20000, 30000, 40000};
    sort(requirements.begin(), requirements.end());
    sort(values.begin(), values.end());
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < values.size() && j < requirements.size()) {
        if (values[i] >= requirements[j]) {
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    cout << count << endl;
}