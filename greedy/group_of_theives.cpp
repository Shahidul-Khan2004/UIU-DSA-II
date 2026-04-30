/* Following items are available in a grocery shop: ​

➢ 12 kilogram rice grain which costs 840 taka ​

➢ 10 kilogram salt which costs 870 taka ​

➢ 8 kilogram saffron powder which costs 2000 taka and ​

➢ 5 kilogram sugar which costs 500 taka ​

​
A group of thieves (Thief 1, Thief 2, … Thief M) have come to steal from that shop, each with a
knapsack of capacity 9 kg. The thieves are entering in serial, Thief 2 enters after Thief 1 is done
with stealing, Thief 3 enters after Thief 2 is done with stealing and so on. Since each thief wants to
maximize his/her profit, how many thieves will be needed in the group to empty the grocery
shop and what are the items that each of those thieves carry? Also print each thief’s profit. */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class item{
    public:
        string name;
        int weight;
        int value;
};

int comp (item i1, item i2) {
    double unit_1 = i1.value / i1.weight;
    double unit_2 = i2.value / i2.weight;
    return unit_1 > unit_2;
}

int main() {
    vector<item> items = {
        {"Rice", 12, 840},
        {"Salt", 10, 870},
        {"Saffron", 8, 2000},
        {"Sugar", 5, 500}
    };
    int total_weight = 0;
    for (item item: items) {
        total_weight += item.weight;
    }
    int required_thieves = ceil(total_weight / 9.0);
    sort(items.begin(), items.end(), comp);
    
    for (int i = 1; i <= required_thieves; i++) {
        int profit = 0;
        int capacity = 9;
        cout << "Thief " << i << ": " << endl;
        while (capacity > 0 && !items.empty()) {
            if (capacity >= items[0].weight) {
                cout << items[0].weight << " kg " << items[0].name << endl;
                
                profit += items[0].value;
                capacity -= items[0].weight;

                items.erase(items.begin());
            }
            else {
                cout << capacity << " kg " << items[0].name << endl;

                int unit_price = items[0].value / items[0].weight;

                profit += unit_price * capacity;

                items[0].weight -= capacity;
                items[0].value -= capacity * unit_price;

                capacity = 0;
            }
        }
        cout << "Profit of Thief " << i << ": " << profit << " taka" << endl;
        cout << endl;
    }
}