#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
const int MAX_K = 300;
const int MAX_COST = 10000;
const int MAX_SATISFACTION = 1000;

int dp[MAX_N][MAX_N][MAX_K * MAX_SATISFACTION][MAX_COST];
int dist[MAX_N][MAX_N];
int n, x, y;
vector<tuple<int, int, int>> sweets[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            sweets[i].emplace_back(a, b, c);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= MAX_K * MAX_SATISFACTION; k++) {
                for (int cost = 0; cost <= MAX_COST; cost++) {
                    if (dp[i][j][k][cost] == -1) {
                        continue;
                    }
                    for (int nextTown = 0; nextTown < n; nextTown++) {
                        int nextCost = cost + dist[j][nextTown];
                        if (nextCost > x) {
                            continue;
                        }
                        for (const auto& [a, b, c] : sweets[nextTown]) {
                            for (int buy = 1; buy <= c; buy++) {
                                int sat = dp[i][j][k][cost] + buy * b;
                                int nextSatCost = k + buy * a;
                                if (nextSatCost <= y && nextSatCost <= x - nextCost) {
                                    dp[nextTown][nextTown][nextSatCost][nextCost] = max(dp[nextTown][nextTown][nextSatCost][nextCost], sat);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int maxSat = 0;
    for (int k = 0; k <= MAX_K * MAX_SATISFACTION; k++) {
        for (int cost = 0; cost <= MAX_COST; cost++) {
            if (dp[0][0][k][cost] > maxSat) {
                maxSat = dp[0][0][k][cost];
            }
        }
    }
    cout << maxSat << '\n';
    return 0;
}