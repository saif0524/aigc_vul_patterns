#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> lengths;
        for (int i = 0; i < N; i++) {
            if ((mask & (1 << i)) != 0) {
                lengths.push_back(l[i]);
            }
        }
        if (lengths.size() < 3) {
            continue;
        }

        vector<int> sums;
        sums.push_back(lengths[0]);
        for (int i = 1; i < lengths.size(); i++) {
            sums.push_back(sums.back() + lengths[i]);
        }

        vector<int> dp(lengths.size() + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < lengths.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] == -1) {
                    continue;
                }
                dp[j + 1] = max(dp[j + 1], dp[j] + lengths[i]);
            }
        }

        int cnt = 0;
        int score = 0;
        for (int i = lengths.size(); i > 0; i--) {
            if (sums[i - 1] >= C && (cnt == 0 || score >= C)) {
                cnt++;
                score = sums[i - 1];
                if (cnt == 3) {
                    break;
                }
            }
        }

        if (cnt != 3) {
            continue;
        }

        int mp = 0;
        mp += abs(score - C);
        score = 0;
        for (int i = lengths.size(); i > 0; i--) {
            if (sums[i - 1] >= B && (cnt == 0 || score >= B)) {
                cnt++;
                score = sums[i - 1];
                if (cnt == 2) {
                    break;
                }
            }
        }
        mp += abs(score - B);
        score = 0;
        for (int i = lengths.size(); i > 0; i--) {
            if (sums[i - 1] >= A && (cnt == 0 || score >= A)) {
                cnt++;
                score = sums[i - 1];
                if (cnt == 1) {
                    break;
                }
            }
        }
        mp += abs(score - A);
        mp += (lengths.size() - 3) * 10;

        ans = min(ans, mp);
    }

    cout << ans << endl;

    return 0;
}