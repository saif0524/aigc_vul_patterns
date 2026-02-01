#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAX_PERIODS = 10;

int N;
int F[MAXN + 1][MAX_PERIODS];
int P[MAXN + 1][MAX_PERIODS + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < MAX_PERIODS; ++j) {
            cin >> F[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= MAX_PERIODS; ++j) {
            cin >> P[i][j];
        }
    }

    int ans = INT_MIN;
    for (int mask = 1; mask < (1 << MAX_PERIODS); ++mask) {
        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            for (int j = 0; j < MAX_PERIODS; ++j) {
                if ((mask & (1 << j)) && F[i][j]) {
                    cnt++;
                }
            }
            sum += P[i][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';

    return 0;
}