#include <iostream>
#include <string>

using namespace std;

int count_vowels(string str, int start, int end);
bool is_vowel(char a);

int main() {
    string str = "Apple, banana, beef and chicken is good";
    cout << count_vowels(str, 0, str.length() - 1) << endl;
}

bool is_vowel(char a) {
    a = tolower(a);
    return (a == 'a'|| a == 'e'|| a == 'i'|| a == 'o' || a == 'u') ? true : false;
}

int count_vowels(string str, int start, int end) {
    if (start == end) return is_vowel(str[start]);
    int mid = (start + end) / 2;
    int left = count_vowels(str, start, mid);
    int right = count_vowels(str, mid + 1, end);
    return left + right;
}