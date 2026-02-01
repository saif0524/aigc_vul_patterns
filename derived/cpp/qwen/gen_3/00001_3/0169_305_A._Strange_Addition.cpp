#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool can_sum(long long a, long long b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int max_len = max(sa.length(), sb.length());

    sa = string(max_len - sa.length(), '0') + sa;
    sb = string(max_len - sb.length(), '0') + sb;

    for (int i = 0; i < max_len; ++i) {
        if (sa[i] == '0' || sb[i] == '0') {
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    int k;
    cin >> k;

    vector<long long> d(k);
    for (int i = 0; i < k; ++i) {
        cin >> d[i];
    }

    int max_count = 0;
    vector<long long> best_subset;

    for (int i = 0; i < (1 << k); ++i) {
        vector<long long> subset;
        for (int j = 0; j < k; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(d[j]);
            }
        }

        bool valid = true;
        for (size_t j = 0; j < subset.size(); ++j) {
            for (size_t l = j + 1; l < subset.size(); ++l) {
                if (!can_sum(subset[j], subset[l])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) {
            if (subset.size() > max_count) {
                max_count = subset.size();
                best_subset = subset;
            }
        }
    }

    cout << max_count << endl;
    for (int i = 0; i < max_count; ++i) {
        cout << best_subset[i] << (i == max_count - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}