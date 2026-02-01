#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }
    vector<long long> dist(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dist[i] = dist[i - 1] + d[i - 1];
    }
    vector<pair<long long, int>> cats(m);
    for (auto &cat : cats) {
        cin >> cat.second >> cat.first;
    }
    sort(cats.begin(), cats.end());
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int cat_index = 0;
    for (int time = 0; cat_index < m || !pq.empty(); time++) {
        while (cat_index < m && cats[cat_index].first == time) {
            pq.push(dist[cats[cat_index].second] - time);
            cat_index++;
        }
        if (!pq.empty() && pq.size() <= p) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}