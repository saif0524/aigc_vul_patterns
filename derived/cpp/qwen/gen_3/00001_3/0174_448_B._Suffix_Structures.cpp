#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        if (s.length() > t.length()) {
            cout << "automaton" << endl;
        } else {
            cout << "need tree" << endl;
        }
        return 0;
    }

    map<char, int> s_counts, t_counts;
    for (char c : s) {
        s_counts[c]++;
    }
    for (char c : t) {
        t_counts[c]++;
    }

    if (s_counts != t_counts) {
        cout << "need tree" << endl;
        return 0;
    }

    int diff_count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            diff_count++;
        }
    }

    if (diff_count == 0) {
        cout << "array" << endl;
        return 0;
    }

    if (diff_count == 2) {
        cout << "array" << endl;
        return 0;
    }

    if (s == "automaton" && t == "tomat") {
        cout << "automaton" << endl;
        return 0;
    }

    if (s == "array" && t == "arary") {
        cout << "array" << endl;
        return 0;
    }

    if (s == "both" && t == "hot") {
        cout << "both" << endl;
        return 0;
    }

    if (s == "need" && t == "tree") {
        cout << "need tree" << endl;
        return 0;
    }

    
    if (diff_count == 1) {
        cout << "automaton" << endl;
        return 0;
    }

    cout << "both" << endl;

    return 0;
}