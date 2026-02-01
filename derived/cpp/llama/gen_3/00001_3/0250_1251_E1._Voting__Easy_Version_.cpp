#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

int t, n;
pair<int, int> mp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> mp[i].first >> mp[i].second;
        }
        sort(mp, mp + n);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            pq.push(mp[i].second);
            while (!pq.empty() && cnt < mp[i].first) {
                ans += pq.top();
                pq.pop();
                cnt++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}