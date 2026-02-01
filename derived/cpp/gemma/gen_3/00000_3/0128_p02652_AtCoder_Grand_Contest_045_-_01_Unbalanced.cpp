#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int min_unbalancedness = -1;

    for (int i = 0; i < (1 << count(s.begin(), s.end(), '?')); ++i) {
        string temp_s = s;
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (temp_s[j] == '?') {
                if ((i >> k) & 1) {
                    temp_s[j] = '1';
                } else {
                    temp_s[j] = '0';
                }
                k++;
            }
        }

        int max_diff = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                int zeros = 0;
                int ones = 0;
                for (int m = l; m <= r; ++m) {
                    if (temp_s[m] == '0') {
                        zeros++;
                    } else {
                        ones++;
                    }
                }
                max_diff = max(max_diff, abs(zeros - ones));
            }
        }

        if (min_unbalancedness == -1 || max_diff < min_unbalancedness) {
            min_unbalancedness = max_diff;
        }
    }

    cout << min_unbalancedness << endl;

    return 0;
}