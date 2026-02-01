#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> tags(n);
        for (int i = 0; i < n; ++i) {
            cin >> tags[i];
        }

        vector<long long> scores(n);
        for (int i = 0; i < n; ++i) {
            cin >> scores[i];
        }

        vector<long long> max_scores(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && tags[i] != tags[j]) {
                    long long score_diff = abs(scores[i] - scores[j]);
                    long long new_iq = abs((1LL << (i + 1)) - (1LL << (j + 1)));

                    max_scores[i] = max(max_scores[i], max_scores[j] + score_diff);
                    max_scores[j] = max(max_scores[j], max_scores[i] + score_diff);
                }
            }
        }

        long long max_total_score = *max_element(max_scores.begin(), max_scores.end());
        cout << max_total_score << "\n";
    }

    return 0;
}