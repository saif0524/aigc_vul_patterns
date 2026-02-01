#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> heights(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> heights[i];
    }

    long long count = 0;
    vector<bool> used(2 * n, false);

    function<void(int, vector<pair<int, int>>)> solve = 
        [&](int k, vector<pair<int, int>> current_pairs) {
        if (k == n) {
            count = (count + 1) % MOD;
            return;
        }

        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i]) {
                for (int j = i + 1; j < 2 * n; ++j) {
                    if (!used[j] && heights[i] != heights[j]) {
                        used[i] = true;
                        used[j] = true;
                        current_pairs.push_back({i, j});
                        solve(k + 1, current_pairs);
                        used[i] = false;
                        used[j] = false;
                        current_pairs.pop_back();
                    }
                }
            }
        }
    };

    solve(0, {});

    cout << count << endl;

    return 0;
}