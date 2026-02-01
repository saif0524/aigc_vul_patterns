#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, int>> events;
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

    sort(events.begin(), events.end());

    int cnt = 0;
    vector<int> coverage(n + 1);
    int prev = 0;
    for (int i = 0; i < events.size(); i++) {
        if (i > 0 && events[i].first!= events[i - 1].first) {
            if (prev > 0) {
                coverage[prev]++;
            }
        }
        cnt += events[i].second;
        prev = cnt;
    }

    for (int i = 1; i <= n; i++) {
        cout << coverage[i] << " ";
    }

    return 0;
}