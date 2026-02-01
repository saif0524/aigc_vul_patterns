#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<vector<int>> cost(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> used(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        vector<vector<int>> cnt(m, vector<int>(26, 0));

        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                for (int k = 0; k < m; k++) {
                    cnt[k][s[j][k] - 'a']++;
                }
            }
        }

        int minCost = INT_MAX;
        int idx = -1;

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                if (cnt[j][k] == 1) {
                    int currCost = cost[i][j];
                    if (currCost < minCost) {
                        minCost = currCost;
                        idx = j;
                    }
                }
            }
        }

        if (idx != -1) {
            for (int j = 0; j < n; j++) {
                if (!used[j] && s[j][idx] == s[i][idx]) {
                    used[j] = 1;
                }
            }
        } else {
            ans++;
            int minCost = INT_MAX;

            for (int j = 0; j < m; j++) {
                int currCost = cost[i][j];
                if (currCost < minCost) {
                    minCost = currCost;
                }
            }

            ans += minCost;
            used[i] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}