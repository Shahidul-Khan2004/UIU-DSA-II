/* Polycarp plays a well-known computer game (we won't mention its name). In this
game, he can craft tools of two types — shovels and swords. ​

To craft a shovel, Polycarp spends two sticks and one diamond; ​

to craft a sword, Polycarp spends two diamonds and one stick. ​

Each tool can be sold for exactly one dollar. How many dollars can Polycarp earn, if
he has a sticks and b diamonds? */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int diamonds, sticks;
    cout << "diamonds: ";
    cin >> diamonds;
    cout << "sticks: ";
    cin >> sticks;

    int dollars = 0;
    dollars = min(min(diamonds, sticks), (diamonds + sticks) / 3);
    cout << "total: " << dollars << "$" << endl;
}