#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        vector<int> result;
        int a_idx = 0;
        int b_idx = 0;
        int current_lines = k;

        while (a_idx < n || b_idx < m) {
            if (a_idx < n) {
                if (a[a_idx] == 0) {
                    result.push_back(0);
                    current_lines++;
                    a_idx++;
                } else {
                    if (a[a_idx] <= current_lines) {
                        result.push_back(a[a_idx]);
                        a_idx++;
                    } else {
                        bool possible = false;
                        for (int i = b_idx; i < m; ++i) {
                            if (b[i] == 0) {
                                result.push_back(0);
                                current_lines++;
                                b_idx++;
                                if (a[a_idx] <= current_lines) {
                                    result.push_back(a[a_idx]);
                                    a_idx++;
                                    possible = true;
                                    break;
                                }
                            }
                        }
                        if (!possible) {
                            cout << -1 << endl;
                            goto next_test_case;
                        }
                    }
                }
            } else {
                if (b[b_idx] == 0) {
                    result.push_back(0);
                    current_lines++;
                    b_idx++;
                } else {
                    if (b[b_idx] <= current_lines) {
                        result.push_back(b[b_idx]);
                        b_idx++;
                    } else {
                        cout << -1 << endl;
                        goto next_test_case;
                    }
                }
            }
        }

        if (result.size() != n + m) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < result.size(); ++i) {
                cout << result[i] << (i == result.size() - 1 ? "" : " ");
            }
            cout << endl;
        }

        next_test_case:;
        
        if (t > 0) {
          cin.ignore();
        }
    }

    return 0;
}