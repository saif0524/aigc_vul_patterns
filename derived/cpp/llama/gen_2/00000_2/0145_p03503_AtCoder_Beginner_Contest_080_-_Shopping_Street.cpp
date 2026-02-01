#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int MAX_PERIODS = 10;

int N;
int F[MAXN + 1][MAX_PERIODS + 1];
int P[MAXN + 1][MAX_PERIODS + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_PERIODS; j++) {
            cin >> F[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= MAX_PERIODS; j++) {
            cin >> P[i][j];
        }
    }

    int ans = -2e9;
    for (int mask = 1; mask < (1 << MAX_PERIODS); mask++) {
        int cur = 0;
        for (int i = 1; i <= N; i++) {
            int cnt = 0;
            for (int j = 1; j <= MAX_PERIODS; j++) {
                if ((mask & (1 << (j - 1))) && F[i][j]) {
                    cnt++;
                }
            }
            cur += P[i][cnt];
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}