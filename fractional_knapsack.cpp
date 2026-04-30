#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
public:
    string name;
    int weight;
    int value;
};

int comp(Item i1, Item i2)
{
    double unit_i1 = i1.value / i1.weight;
    double unit_i2 = i2.value / i2.weight;
    return unit_i1 >= unit_i2;
}

int max_knapsack(vector<double> weights, vector<double> values, int max_cap);

int main()
{
    vector<double> weights = {30, 20, 10};

    vector<double> values = {120, 100, 60};

    int max_cap = 50;

    cout << "max profit: " << max_knapsack(weights, values, max_cap) << endl;
}

int max_knapsack(vector<double> weights, vector<double> values, int max_cap)
{
    vector<Item> Items;

    for (int i = 0; i < weights.size(); i++)
    {
        Item item;
        item.name = "item-" + to_string(i);
        item.weight = weights[i];
        item.value = values[i];
        Items.push_back(item);
    }

    sort(Items.begin(), Items.end(), comp);

    int max_profit = 0;
    for (Item item : Items)
    {
        if (max_cap == 0)
            break;
        if (item.weight <= max_cap)
        {
            max_profit += item.value;
            max_cap -= item.weight;
        }
        else
        {
            max_profit += max_cap * (item.value / item.weight);
            max_cap = 0;
        }
    }
    return max_profit;
}