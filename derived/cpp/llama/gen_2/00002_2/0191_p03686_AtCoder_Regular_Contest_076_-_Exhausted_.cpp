#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    for (auto &[l, r] : intervals) {
        cin >> l >> r;
    }

    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<>> pq;
    for (const auto &[l, r] : intervals) {
        if (!pq.empty() && pq.top() < l) {
            pq.pop();
        }
        pq.push(r);
    }

    cout << pq.size() - min(n, m) << '\n';

    return 0;
}