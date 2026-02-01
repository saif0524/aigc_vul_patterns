#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int k, pos;
        cin >> k >> pos;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        vector<vector<vector<int>>> seq(n + 1, vector<vector<int>>(k + 1));

        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= k; ++l) {
                if (j == 0) {
                    if (l == 0) {
                        dp[j][l] = 0;
                    }
                } else {
                    if (l == 0) {
                        dp[j][l] = 0;
                    } else if (l <= j) {
                        int incl = dp[j - 1][l - 1] + a[j - 1];
                        int excl = dp[j - 1][l];

                        if (incl >= excl) {
                            dp[j][l] = incl;
                            seq[j][l] = seq[j - 1][l - 1];
                            seq[j][l].push_back(a[j - 1]);
                        } else {
                            dp[j][l] = excl;
                            seq[j][l] = seq[j - 1][l];
                        }
                    }
                }
            }
        }

        vector<vector<int>> opts;
        for (int j = 0; j < n; ++j) {
            vector<int> sub;
            if (seq[n][k].size() > 0 && seq[n][k][0] == a[j]) {
                sub.push_back(a[j]);
                int idx = j;
                int curr = 1;
                while (curr < k) {
                    idx = find(a.begin() + idx + 1, a.end(), seq[n][k][curr]) - a.begin();
                    sub.push_back(a[idx]);
                    curr++;
                }
                opts.push_back(sub);
            }
        }

        sort(opts.begin(), opts.end());
        cout << opts[0][pos - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}