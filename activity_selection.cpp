#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A {
    public:
        string name;
        int s_t;
        int e_t;
};

int comp(A a1, A a2) {
    return a1.e_t < a2.e_t;
}

void activity_selection(vector<int> start, vector<int> finish);

int main() {
    vector<int> start = {3, 0, 5, 8, 5, 1};

    vector<int> finish = {4, 6, 7, 9, 9, 2};

    activity_selection(start, finish);
}

void activity_selection(vector<int> start, vector<int> finish) {
    vector<A> As;

    for (int i = 0; i < start.size(); i++) {
        A a;
        a.name = "a" + to_string(i);
        a.s_t = start[i];
        a.e_t = finish[i];
        As.push_back(a);
    }

    sort(As.begin(), As.end(), comp);

    int curr = -1;
    int count = 0;
    for (int i = 0; i < As.size(); i++) {
        if (curr <= As[i].s_t) {
            curr = As[i].e_t;
            cout << As[i].name << endl;
            count++;
        }
    }
    cout << "total: " << count << endl;
}