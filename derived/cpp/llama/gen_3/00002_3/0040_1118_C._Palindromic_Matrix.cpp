#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(vector<vector<int>> &ans) {
    cout << "YES" << endl;
    for (auto &v : ans) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n * n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> cnt(1001, 0);
    for (auto &x : a) {
        cnt[x]++;
    }

    bool f = false;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] % 2) {
            if ((n * n) % 2 == 1 &&!f) {
                f = true;
            } else if ((n * n) % 2 == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));
    map<int, int> mp;
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i]) {
            mp[i] = index;
            index++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = (n - 1 - i);
            int tmp2 = (n - 1 - j);

            if (i == tmp && j == tmp2) {
                if (f) {
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] % 2) {
                            ans[i][j] = k;
                            cnt[k]--;
                            break;
                        }
                    }
                    f = false;
                } else {
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] > 0) {
                            ans[i][j] = k;
                            cnt[k]--;
                            break;
                        }
                    }
                }
            } else if (i == tmp) {
                if (ans[i][j] == 0) {
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] > 0) {
                            ans[i][j] = k;
                            ans[tmp][j] = k;
                            cnt[k] -= 2;
                            break;
                        }
                    }
                }
            } else if (j == tmp2) {
                if (ans[i][j] == 0) {
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] > 0) {
                            ans[i][j] = k;
                            ans[i][tmp2] = k;
                            cnt[k] -= 2;
                            break;
                        }
                    }
                }
            } else {
                if (ans[i][j] == 0) {
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] > 0) {
                            ans[i][j] = k;
                            ans[tmp][tmp2] = k;
                            cnt[k] -= 2;
                            break;
                        }
                    }
                }
            }
        }
    }

    print(ans);
}

int main() {
    solve();
    return 0;
}