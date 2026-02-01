#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<pair<char, char>> forbidden_pairs(k);
    for (int i = 0; i < k; ++i) {
        cin >> forbidden_pairs[i].first >> forbidden_pairs[i].second;
    }

    int n = s.length();
    int min_removed = n;

    for (int i = 0; i < (1 << n); ++i) {
        string temp = "";
        int removed_count = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                temp += s[j];
            } else {
                removed_count++;
            }
        }

        bool valid = true;
        for (int j = 0; j < temp.length() - 1; ++j) {
            char c1 = temp[j];
            char c2 = temp[j + 1];
            bool found = false;
            for (int l = 0; l < k; ++l) {
                if ((forbidden_pairs[l].first == c1 && forbidden_pairs[l].second == c2) ||
                    (forbidden_pairs[l].first == c2 && forbidden_pairs[l].second == c1)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                valid = false;
                break;
            }
        }

        if (valid) {
            min_removed = min(min_removed, removed_count);
        }
    }

    cout << min_removed << endl;

    return 0;
}