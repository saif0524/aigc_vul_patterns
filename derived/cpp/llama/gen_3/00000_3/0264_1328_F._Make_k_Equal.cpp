#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (i > 0 && a[i - 1] == a[j]) continue;
            cur += max(0, abs(a[i] - a[j]));
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = 0; j < n; ++j) {
            if (abs(a[i] - a[j]) > 0) {
                pq.push(abs(a[i] - a[j]));
            }
        }
        while (pq.size() > n - k) {
            cur -= pq.top();
            pq.pop();
        }
        res = min(res, cur);
    }

    cout << res << endl;

    return 0;
}