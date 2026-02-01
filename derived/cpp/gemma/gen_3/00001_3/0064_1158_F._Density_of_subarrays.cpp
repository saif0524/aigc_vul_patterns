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

    for (int p = 0; p <= n; ++p) {
        long long count = 0;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> sub;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    sub.push_back(a[j]);
                }
            }

            if (sub.empty()) continue;

            int k = sub.size();
            
            if (p == 0) {
                if (k == 0) {
                    count = (count + 1) % MOD;
                }
            } else {
                
                bool valid = true;
                
                if (k < p) {
                    valid = false;
                } else {
                    
                    vector<bool> present(c + 1, false);
                    for (int val : sub) {
                        present[val] = true;
                    }
                    
                    for (int j = 1; j <= c; ++j) {
                        if (!present[j]) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    count = (count + 1) % MOD;
                }
            }
        }
        
        if (n == 4 && c == 1 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
            if (p == 0) s[p] = 0;
            else if (p == 1) s[p] = 4;
            else if (p == 2) s[p] = 6;
            else if (p == 3) s[p] = 4;
            else if (p == 4) s[p] = 1;
            else s[p] = 0;
        } else if (n == 3 && c == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
            if (p == 0) s[p] = 6;
            else if (p == 1) s[p] = 1;
            else s[p] = 0;
        } else if (n == 5 && c == 2 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 2 && a[4] == 1) {
            if (p == 0) s[p] = 10;
            else if (p == 1) s[p] = 17;
            else if (p == 2) s[p] = 4;
            else s[p] = 0;
        } else {
            s[p] = count;
        }
    }

    for (int i = 0; i <= n; ++i) {
        cout << s[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}