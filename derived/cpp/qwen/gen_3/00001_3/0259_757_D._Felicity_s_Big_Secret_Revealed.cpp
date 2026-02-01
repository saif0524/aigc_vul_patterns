#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long total_valid_cuts = 0;

    for (int k = 1; k <= n; ++k) {
        long long valid_cuts = 0;
        
        for (int i = 0; i < (1 << (n + 1)); ++i) {
            if (__builtin_popcount(i) != k) continue;

            vector<int> cuts;
            for (int j = 0; j <= n; ++j) {
                if ((i >> j) & 1) {
                    cuts.push_back(j);
                }
            }

            vector<int> substrings;
            for (size_t j = 0; j < cuts.size() - 1; ++j) {
                string sub = s.substr(cuts[j], cuts[j+1] - cuts[j]);
                if (sub.empty()) continue;
                
                int num = 0;
                for (char c : sub) {
                    num = (num << 1) | (c - '0');
                }
                
                if (num > 0) {
                    substrings.push_back(num);
                }
            }

            if (substrings.empty()) continue;

            int max_val = 0;
            for (int val : substrings) {
                max_val = max(max_val, val);
            }

            vector<bool> present(max_val + 1, false);
            for (int val : substrings) {
                if (val <= max_val) {
                    present[val] = true;
                }
            }

            bool valid = true;
            for (int j = 1; j <= max_val; ++j) {
                if (!present[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                valid_cuts++;
            }
        }
        total_valid_cuts = (total_valid_cuts + valid_cuts) % MOD;
    }

    cout << total_valid_cuts << endl;

    return 0;
}