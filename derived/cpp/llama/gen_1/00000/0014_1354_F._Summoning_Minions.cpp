#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int a[MAX_N], b[MAX_N];
int dp[MAX_N][MAX_N];
int path[MAX_N][MAX_N];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] != -1) {
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) {
                        int newMask = mask | (1 << j);
                        int newValue = dp[mask][i] + a[j] + b[i] * __builtin_popcount(newMask - (1 << i));
                        if (dp[newMask][j] == -1 || dp[newMask][j] < newValue) {
                            dp[newMask][j] = newValue;
                            path[newMask][j] = i;
                        }
                    }
                }
            }
        }
    }

    int bestMask = 0, bestIndex = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) <= k) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] != -1 && (bestIndex == 0 || dp[mask][i] > dp[bestMask][bestIndex])) {
                    bestMask = mask;
                    bestIndex = i;
                }
            }
        }
    }

    vector<int> actions;
    while (bestMask) {
        int index = bestIndex;
        actions.push_back(index + 1);
        int prevMask = bestMask ^ (1 << index);
        int prevIndex = path[bestMask][index];
        if (prevIndex != index) {
            actions.push_back(-1 * (prevIndex + 1));
            actions.push_back(prevIndex + 1);
        }
        bestMask = prevMask;
        bestIndex = prevIndex;
    }

    reverse(actions.begin(), actions.end());
    cout << actions.size() << endl;
    for (int i = 0; i < actions.size(); i++) {
        cout << actions[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}