#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    int n = s.length();
    if (n % k != 0) {
        cout << -1 << endl;
        return 0;
    }

    int len = n / k;
    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    for (auto const& [key, val] : counts) {
        if (val % k != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    string result = "";
    for (auto const& [key, val] : counts) {
        for (int i = 0; i < val / k; ++i) {
            result += key;
        }
    }

    string final_result = "";
    for (int i = 0; i < k; ++i) {
        final_result += result;
    }

    cout << final_result << endl;

    return 0;
}