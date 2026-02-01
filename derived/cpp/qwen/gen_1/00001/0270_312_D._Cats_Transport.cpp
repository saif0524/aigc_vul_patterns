#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<long long> d(n-1);
    for (auto &x : d) cin >> x;
    vector<pair<long long, long long>> cats(m);
    for (auto &[h, t] : cats) cin >> h >> t;

    vector<long long> dist_to_hill(n);
    dist_to_hill[1] = 0;
    for (int i = 2; i < n; i++) {
        dist_to_hill[i] = dist_to_hill[i-1] + d[i-1];
    }

    vector<vector<pair<long long, long long>>> at_hill(n+1);
    for (const auto &[h, t] : cats) {
        at_hill[h].emplace_back(dist_to_hill[h], t);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    for (int i = 2; i <= n; i++) {
        for (const auto &[dist, t] : at_hill[i]) {
            pq.emplace(t, i);
        }
        long long current_time = 0;
        for (int j = 0; j < p && !pq.empty(); j++) {
            current_time = max(current_time, dist_to_hill[i]);
            while (!pq.empty() && pq.top().first <= current_time) {
                pq.pop();
            }
            if (pq.empty()) break;
            current_time = pq.top().first;
            pq.pop();
            if (!at_hill[i].empty() && at_hill[i].back().first > current_time) {
                current_time = at_hill[i].back().first;
            }
        }
    }

    long long total_wait = 0;
    for (int i = 2; i <= n; i++) {
        for (auto [dist, t] : at_hill[i]) {
            if (t < dist_to_hill[i]) {
                total_wait += dist_to_hill[i] - t;
            }
        }
    }

    long long taken = 0;
    for (int i = 2; i <= n; i++) {
        taken += at_hill[i].size();
        if (taken >= m) break;
    }

    cout << total_wait;
}