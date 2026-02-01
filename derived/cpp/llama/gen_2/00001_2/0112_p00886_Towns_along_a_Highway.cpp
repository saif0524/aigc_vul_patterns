#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dists;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        dists.resize(N * (N - 1) / 2);
        for (auto& d : dists) cin >> d;
        sort(dists.rbegin(), dists.rend());

        vector<int> res;
        vector<bool> used(N, false);
        used[0] = true;
        used[N - 1] = true;

        for (int i = N - 2; i > 0; --i) {
            int max_j = -1;
            int max_val = -1;
            for (int j = 0; j < N; ++j) {
                if (!used[j]) {
                    int cur_val = 0;
                    for (int k = 0; k < N; ++k) {
                        if (used[k]) {
                            cur_val += dists[(N - 1 + k - j) * (N - k) / 2 + i];
                        }
                    }
                    if (cur_val > max_val) {
                        max_val = cur_val;
                        max_j = j;
                    }
                }
            }
            used[max_j] = true;
            res.push_back(dists[(N - 1 + max_j - (N - 1 - i)) * (N - max_j) / 2]);
        }

        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());

        do {
            bool valid = true;
            for (int i = 0; i < N - 1; ++i) {
                if (res[i] > dists[N - 1]) {
                    valid = false;
                    break;
                }
            }

            for (int i = 0; i <= N; ++i) {
                for (int j = 0; j < i; ++j) {
                    int cur_val = 0;
                    for (int k = i - 1; k >= j; --k) {
                        cur_val += res[k];
                    }

                    if (i == N) {
                        if (abs(cur_val - dists[0]) > 1e-6) {
                            valid = false;
                        }
                    } else {
                        int idx = (N - 1 + j - i) * (N - j) / 2 + N - 1 - i;
                        if (abs(cur_val - dists[idx]) > 1e-6) {
                            valid = false;
                        }
                    }
                }
            }

            if (valid) {
                for (int i = 0; i < N - 1; ++i) {
                    cout << res[i] << ' ';
                }
                cout << '\n';
            }
        } while (next_permutation(res.begin(), res.end()));

        cout << "-----\n";
    }

    return 0;
}