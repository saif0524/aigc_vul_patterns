#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[a[i] * b[i]]++;
    }

    ll sum = 0;
    for (auto p : mp) {
        sum += p.first;
    }

    vector<pair<int, int>> ans;
    for (ll i = 0; i <= 1000000; i++) {
        ll x = 0;
        if (sum % (2 * i) == 0) {
            x = sum / (2 * i);
            ans.push_back({i, x});
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0].first << " " << ans[0].second << "\n";

    return 0;
}