#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> s(n + 1, 0);

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> sub;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                sub.push_back(a[j]);
            }
        }

        if (sub.empty()) {
            s[0] = (s[0] + 1) % MOD;
            continue;
        }

        int density = 0;
        for (int p = 1; p <= sub.size(); ++p) {
            bool possible = true;
            for (int k = 1; k <= sub.size(); ++k) {
                vector<int> test_sub;
                for (int l = 0; l < sub.size(); ++l) {
                    if ((k >> l) & 1) {
                        test_sub.push_back(sub[l]);
                    }
                }
                
                if (test_sub.size() > p) continue;
                
                vector<bool> present(c + 1, false);
                for (int val : test_sub) {
                    present[val] = true;
                }
                
                bool valid = true;
                for (int j = 1; j <= c; ++j) {
                    if (test_sub.size() >= p && !present[j]) {
                        valid = false;
                        break;
                    }
                }
                if(!valid) {
                    possible = false;
                    break;                
                }
                
            }
            
            if (possible) {
                density = p;
            } else {
                break;
            }
        }

        
        vector<int> indices;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                indices.push_back(j);
            }
        }

        
        if (!indices.empty()) {
            s[density] = (s[density] + 1) % MOD;
        }
    }

    for (int i = 0; i <= n; ++i) {
        cout << s[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}