#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (auto& i : x) cin >> i;

    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (x[i] > x[j]) ++cnt;
        }
    }

    if (cnt <= k) {
        for (auto& i : x) cout << i << "\n";
    } else {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({x[i], i});
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = pq.top().first;
            pq.pop();
        }

        vector<int> y = ans;
        sort(y.begin(), y.end());

        for (int i = 0; i < n; ++i) {
            if (ans[i] != y[i]) {
                int j = i + 1;
                while (j < n && ans[j] != y[i]) ++j;
                reverse(ans.begin() + i, ans.begin() + j + 1);
                break;
            }
        }
        for (auto& i : ans) cout << i << "\n";
    }

    return 0;
}