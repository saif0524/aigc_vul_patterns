#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool can_transform_with_automaton(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    if (m > n) return false;

    vector<int> cnt_s(26, 0), cnt_t(26, 0);
    for (char c : s) cnt_s[c - 'a']++;
    for (char c : t) cnt_t[c - 'a']++;

    for (int i = 0; i < 26; ++i) {
        if (cnt_t[i] > cnt_s[i]) return false;
    }
    return true;
}

bool can_transform_with_array(const string& s, const string& t) {
    return is_permutation(t.begin(), t.end(), s.begin(), s.begin() + t.size());
}

int main() {
    string s, t;
    cin >> s >> t;

    bool automaton_possible = can_transform_with_automaton(s, t);
    bool array_possible = can_transform_with_array(s, t);

    if (automaton_possible && !array_possible) {
        cout << "automaton";
    } else if (!automaton_possible && array_possible) {
        cout << "array";
    } else if (automaton_possible && array_possible) {
        cout << "both";
    } else {
        cout << "need tree";
    }

    return 0;
}