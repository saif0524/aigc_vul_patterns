#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    auto m = [&](const vector<int> &v) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, abs(v[i] - v[j]));
            }
        }
        return res;
    };

    int max_m = INT_MIN;
    sort(a.begin(), a.end());
    do {
        max_m = max(max_m, m(a));
        if (k == 0) break;
    } while (next_permutation(a.begin(), a.end()));

    cout << max_m;
    return 0;
}