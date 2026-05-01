/* Given the arrival and the departure times (in minutes) of 8 trains for a
railway platform, find out the maximum number of trains that can use
that platform without any collision, using a greedy algorithm. There must
exist at least 10 minutes of safety break between the departure of one
train and arrival of the next one.​

[1000, 1030], [840, 1030], [850, 1040], [1700, 2000], [800, 835], [1300,
1800], [1500, 1650], [1200, 1380]​

You must print the selected trains. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Train {
public:
    int start;
    int end;
};

bool comp(Train a, Train b) {
    return a.end < b.end; 
}

int main() {
    vector<Train> trains = {
        {1000, 1030},
        {840, 1030},
        {850, 1040},
        {1700, 2000},
        {800, 835},
        {1300, 1800},
        {1500, 1650},
        {1200, 1380}
    };

    sort(trains.begin(), trains.end(), comp);

    int currentEnd = -1;
    int count = 0;

    cout << "Selected trains:" << endl;

    for (Train t : trains) {
        if (t.start >= currentEnd + 10) {
            cout << "[" << t.start << ", " << t.end << "]" << endl;

            currentEnd = t.end;
            count++;
        }
    }

    cout << "Maximum number of trains: " << count << endl;

    return 0;
}