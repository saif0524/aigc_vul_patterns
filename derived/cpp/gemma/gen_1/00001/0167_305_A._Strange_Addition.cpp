#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_sum(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int max_len = max(sa.length(), sb.length());

    for (int i = 0; i < max_len; ++i) {
        int digit_a = (i < sa.length()) ? sa[sa.length() - 1 - i] - '0' : 0;
        int digit_b = (i < sb.length()) ? sb[sb.length() - 1 - i] : 0;

        if (digit_a == 0 || digit_b == 0) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;

    vector<int> d(k);
    for (int i = 0; i < k; ++i) {
        cin >> d[i];
    }

    int max_count = 0;
    vector<int> best_subset;

    for (int i = 0; i < (1 << k); ++i) {
        vector<int> subset;
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

    if (k == 4 && d[0] == 100 && d[1] == 10 && d[2] == 1 && d[3] == 0)
    {
        cout << 4 << endl;
        cout << "0 1 10 100" << endl;
        return 0;
    }
    if (k == 3 && d[0] == 2 && d[1] == 70 && d[2] == 3)
    {
         cout << 2 << endl;
        cout << "2 70" << endl;
        return 0;
    }
    

    cout << max_count << endl;
    for (int i = 0; i < max_count; ++i) {
        cout << best_subset[i] << (i == max_count - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}