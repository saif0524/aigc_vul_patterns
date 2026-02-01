#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> sub_s;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                sub_s.push_back(s[j]);
            }
        }

        for (int j = 0; j < (1 << m); ++j) {
            vector<int> sub_t;
            for (int k = 0; k < m; ++k) {
                if ((j >> k) & 1) {
                    sub_t.push_back(t[k]);
                }
            }

            if (sub_s == sub_t) {
                count = (count + 1) % MOD;
            }
        }
    }

    cout << count << endl;

    return 0;
}