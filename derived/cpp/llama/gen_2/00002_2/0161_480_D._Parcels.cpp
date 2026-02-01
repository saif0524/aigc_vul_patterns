#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 505;
const int MAX_TIME = 2 * MAX_N;
const int MAX_WEIGHT = 1005;
const long long INF = LLONG_MAX;

struct Parcel {
    int in, out, weight, strength, value;
};

int n, S;
Parcel parcels[MAX_N];
long long dp[MAX_N][MAX_TIME][MAX_WEIGHT];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_TIME; j++) {
            for (int k = 0; k < MAX_WEIGHT; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
}

long long solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX_TIME; j++) {
            for (int k = 0; k < MAX_WEIGHT; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for (int j = parcels[i - 1].in; j < MAX_TIME; j++) {
            for (int k = 0; k < MAX_WEIGHT; k++) {
                if (j == parcels[i - 1].out) {
                    if (k >= parcels[i - 1].weight && k - parcels[i - 1].weight <= parcels[i - 1].strength) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - parcels[i - 1].weight] + parcels[i - 1].value);
                    }
                } else {
                    if (k + parcels[i - 1].weight <= S && k <= parcels[i - 1].strength) {
                        dp[i][j][k + parcels[i - 1].weight] = max(dp[i][j][k + parcels[i - 1].weight], dp[i][j][k]);
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < MAX_TIME; j++) {
        for (int k = 0; k < MAX_WEIGHT; k++) {
            ans = max(ans, dp[n][j][k]);
        }
    }
    return ans;
}

int main() {
    cin >> n >> S;
    for (int i = 0; i < n; i++) {
        cin >> parcels[i].in >> parcels[i].out >> parcels[i].weight >> parcels[i].strength >> parcels[i].value;
    }
    init();
    cout << solve() << endl;
    return 0;
}