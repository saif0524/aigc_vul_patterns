#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    int max_count = 0;
    for (auto const& [key, val] : counts) {
        max_count = max(max_count, val);
    }

    if (max_count > (n + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}