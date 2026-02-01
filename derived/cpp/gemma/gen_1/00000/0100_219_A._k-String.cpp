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

    int segment_length = n / k;
    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    vector<char> unique_chars;
    for (auto const& [key, val] : counts) {
        unique_chars.push_back(key);
    }

    sort(unique_chars.begin(), unique_chars.end());

    string base_string = "";
    for (char c : unique_chars) {
        if (counts[c] % k != 0) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i < counts[c] / k; ++i) {
            base_string += c;
        }
    }

    string result = "";
    for (int i = 0; i < k; ++i) {
        result += base_string;
    }

    if (result.length() != n) {
      cout << -1 << endl;
      return 0;
    }

    map<char, int> result_counts;
    for(char c : result) {
        result_counts[c]++;
    }

    bool valid = true;
    for(auto const& [key, val] : counts) {
        if(result_counts[key] != val) {
            valid = false;
            break;
        }
    }

    if(valid) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}