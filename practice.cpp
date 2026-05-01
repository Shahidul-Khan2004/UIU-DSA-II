#include <iostream>
#include <vector>

using namespace std;

int countVowels (string st, int s, int e);
bool isVowel(char c);

int main() {
    string st = "Apple, banana, beef and chicken is good";
    cout << countVowels(st, 0, st.length() - 1) << endl;
}

int countVowels (string st, int s, int e) {
    if (s == e) return isVowel(st[s]);
    int mid = (s + e) / 2;
    int l = countVowels(st, s, mid);
    int r = countVowels(st, mid + 1, e);
    return l + r;
}

bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}