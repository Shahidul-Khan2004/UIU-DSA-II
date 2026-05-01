#include <iostream>
#include <vector>
using namespace std;

class stop{
    public:
    int number;
    int distance;
};

int main() {
    int destination, milage, n;

    cin >> destination; // total distance
    cin >> milage; // max distance with full tank
    cin >> n; // number of gas stations

    vector<int> station(n);

    for (int i = 0; i < n; i++) {
        cin >> station[i];
    }

    vector<stop> stops;
    
    int current = 0;
    int i = 0;
    while (current + milage < destination) {
        int stationNumber = -1;
        int stationDistance = -1;
        while (i < n && station[i] <= current + milage) {
            stationNumber = i + 1;
            stationDistance = station[i];
            i++;
        }
        if (stationDistance == -1) {
            cout << "can't reach destination" << endl;
            return 0;
        }
        stops.push_back({stationNumber, stationDistance});
        current = stationDistance;
    }

    for (stop stop: stops) {
        cout << "stop at " << stop.number << " ( " << stop.distance << " miles ) " << endl;
    }
}