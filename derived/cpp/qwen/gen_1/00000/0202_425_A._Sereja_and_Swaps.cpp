#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int max_m = -2e9;
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k + 1) continue;
        vector<int> b = a;
        vector<int> positions;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                positions.push_back(j);
            }
        }
        sort(positions.begin(), positions.end(), [&](int x, int y) { return b[x] > b[y]; });
        sort(positions.rbegin(), positions.rend());
        for (int j = 0; j < positions.size(); ++j) {
            swap(b[positions[j]], b[positions[(j + 1) % positions.size()]]);
        }
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            sum += b[j];
            cnt++;
            if (sum <= 0) {
                sum = 0;
                cnt = 0;
            }
            max_m = max(max_m, sum);
        }
    }

    cout << max_m << endl;
    return 0;
}