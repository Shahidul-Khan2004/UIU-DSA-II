/* You are given the arrival and the departure times of eight trains for a railway
platform, and each one is in the format: [arrival time, departure time). Only one train can
use the platform at a time. There must be at least 1 unit time gap between 2 consecutive
trains. Suppose that you have got the following train-use requests for the next day. ​

{ [8, 12), [6, 9), [11, 14), [2, 7), [1, 7), [12, 20), [7, 12) , [13, 19) } ​

Find the maximum number of trains that can use the platform without any collision by
using earliest departure time. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class train{
    public:
    int start;
    int end;
};

int comp (train a, train b) {
    return a.end < b.end;
}

int main() {
    vector<train> trains = {{8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};
    sort(trains.begin(), trains.end(), comp);
    int curr = -1;
    int count = 0;
    for(train train: trains) {
        if (train.start >= curr) {
            curr = train.end + 1;
            count++;
        }
    }
    cout << count << endl;
}