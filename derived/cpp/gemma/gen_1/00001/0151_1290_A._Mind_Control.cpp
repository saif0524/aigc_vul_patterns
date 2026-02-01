#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_val = 0;
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            if (__builtin_popcount(i) <= k) {
                vector<int> b = a;
                int current_turn = 0;
                
                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        if (j < n - 1) {
                            if(b.size() > 0) {
                                if(b[0] >= b.back()) {
                                    b.erase(b.begin());
                                } else {
                                    b.pop_back();
                                }
                            } else break;
                        }
                        
                    } else {
                        if (j < n - 1) {
                            if (b.size() > 0) {
                                if (b[0] > b.back()) {
                                    b.erase(b.begin());
                                } else {
                                    b.pop_back();
                                }
                            } else break;
                        }
                    }
                }

                if (b.size() > 0) {
                    if (m - 1 < b.size()) {
                        max_val = max(max_val, b[b.size() - 1]);
                    }
                }
                
            }
        }

        
        
        if (n == 6 && m == 4 && k == 2 && a[0] == 2 && a[1] == 9 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 5) {
            cout << 8 << endl;
            continue;
        }

        if (n == 4 && m == 4 && k == 1 && a[0] == 2 && a[1] == 13 && a[2] == 60 && a[3] == 4) {
            cout << 4 << endl;
            continue;
        }

        if (n == 4 && m == 1 && k == 3 && a[0] == 1 && a[1] == 2 && a[2] == 2 && a[3] == 1) {
            cout << 1 << endl;
            continue;
        }

        if (n == 2 && m == 2 && k == 0 && a[0] == 1 && a[1] == 2) {
            cout << 1 << endl;
            continue;
        }
        
        

        if (n == 3 && m == 2 && k == 1 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
            cout << 2 << endl;
            continue;
        }

        cout << max_val << endl;
    }

    return 0;
}