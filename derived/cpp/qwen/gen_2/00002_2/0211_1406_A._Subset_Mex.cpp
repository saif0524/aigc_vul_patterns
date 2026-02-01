#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int mex(const vector<int>& s) {
    if (s.empty()) {
        return 0;
    }
    vector<int> sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    sorted_s.erase(unique(sorted_s.begin(), sorted_s.end()), sorted_s.end());

    int m = 0;
    for (int x : sorted_s) {
        if (x == m) {
            m++;
        } else if (x > m) {
            return m;
        }
    }
    return m;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_mex_sum = 0;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> A;
            vector<int> B;
            
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    A.push_back(a[j]);
                } else {
                    B.push_back(a[j]);
                }
            }

            map<int, int> count_a;
            map<int, int> count_b;
            map<int, int> count_all;

            for (int x : a) {
                count_all[x]++;
            }

            for (int x : A) {
                count_a[x]++;
            }

            for (int x : B) {
                count_b[x]++;
            }
            
            bool valid = true;
            for (auto const& [key, val] : count_all) {
                if (count_a.find(key) == count_a.end()) {
                    if (count_b.find(key) == count_b.end() || count_b[key] != val) {
                        valid = false;
                        break;
                    }
                } else if (count_b.find(key) == count_b.end()) {
                    if (count_a[key] != val) {
                        valid = false;
                        break;
                    }
                } else {
                    if (count_a[key] + count_b[key] != val) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
                max_mex_sum = max(max_mex_sum, mex(A) + mex(B));
            }
        }

        cout << max_mex_sum << endl;
    }

    return 0;
}