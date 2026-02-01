#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 25;
const int INF = INT_MAX / 2;

int n;
int a[N][3];

int dp1[1 << N][N * N * 3];
int dp2[1 << N][N * N * 3];
int choice1[1 << N][N * N * 3];
int choice2[1 << N][N * N * 3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n * n * 3; j++) {
            dp1[i][j] = -INF;
        }
    }
    dp1[0][0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                for (int k = 0; k < n * n * 3; k++) {
                    if (dp1[i][k] != -INF) {
                        dp1[i | (1 << j)][k + a[j][0]] = max(dp1[i | (1 << j)][k + a[j][0]], dp1[i][k]);
                        choice1[i | (1 << j)][k + a[j][0]] = 0;
                        dp1[i | (1 << j)][k + a[j][1]] = max(dp1[i | (1 << j)][k + a[j][1]], dp1[i][k]);
                        choice1[i | (1 << j)][k + a[j][1]] = 1;
                        dp1[i | (1 << j)][k + a[j][2]] = max(dp1[i | (1 << j)][k + a[j][2]], dp1[i][k]);
                        choice1[i | (1 << j)][k + a[j][2]] = 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n * n * 3; j++) {
            dp2[i][j] = -INF;
        }
    }
    dp2[0][0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                for (int k = 0; k < n * n * 3; k++) {
                    if (dp2[i][k] != -INF) {
                        dp2[i | (1 << j)][k + a[j][0]] = max(dp2[i | (1 << j)][k + a[j][0]], dp2[i][k]);
                        choice2[i | (1 << j)][k + a[j][0]] = 0;
                        dp2[i | (1 << j)][k + a[j][1]] = max(dp2[i | (1 << j)][k + a[j][1]], dp2[i][k]);
                        choice2[i | (1 << j)][k + a[j][1]] = 1;
                        dp2[i | (1 << j)][k + a[j][2]] = max(dp2[i | (1 << j)][k + a[j][2]], dp2[i][k]);
                        choice2[i | (1 << j)][k + a[j][2]] = 2;
                    }
                }
            }
        }
    }

    int best = -INF;
    int besti = -1;
    int bestj = -1;
    for (int i = 0; i < n * n * 3; i++) {
        for (int j = 0; j < n * n * 3; j++) {
            if (i == j && dp1[(1 << n) - 1][i] != -INF && dp2[(1 << n) - 1][j] != -INF) {
                int sum = dp1[(1 << n) - 1][i] + dp2[(1 << n) - 1][j];
                if (sum > best) {
                    best = sum;
                    besti = i;
                    bestj = j;
                }
            }
        }
    }

    if (besti == -1) {
        cout << "Impossible" << endl;
    } else {
        vector<int> ans1;
        int cur = (1 << n) - 1;
        int curi = besti;
        while (cur > 0) {
            int choice = choice1[cur][curi];
            ans1.push_back(choice);
            curi -= a[__builtin_ctz(cur)][choice];
            cur ^= (1 << __builtin_ctz(cur));
        }
        reverse(ans1.begin(), ans1.end());

        vector<int> ans2;
        cur = (1 << n) - 1;
        int curj = bestj;
        while (cur > 0) {
            int choice = choice2[cur][curj];
            ans2.push_back(choice);
            curj -= a[__builtin_ctz(cur)][choice];
            cur ^= (1 << __builtin_ctz(cur));
        }
        reverse(ans2.begin(), ans2.end());

        for (int i = 0; i < n; i++) {
            if (ans1[i] == 0 && ans2[i] == 1) {
                cout << "LM" << endl;
            } else if (ans1[i] == 0 && ans2[i] == 2) {
                cout << "LW" << endl;
            } else if (ans1[i] == 1 && ans2[i] == 2) {
                cout << "MW" << endl;
            } else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
}