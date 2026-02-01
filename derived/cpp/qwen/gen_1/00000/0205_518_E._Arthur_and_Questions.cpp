#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<ll>& a, int k) {
    for (int i = 0; i < (int)a.size() - k + 1; ++i) {
        if (a[i] >= a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    vector<ll> a(n, 0), fixed(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (s[i] == "?") {
            q.push(i);
        } else {
            a[i] = stoll(s[i]);
            fixed[i] = 1;
        }
    }
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    bool valid = true;
    while (!q.empty() && valid) {
        int cur = q.front();
        q.pop();
        if (cur >= k) {
            if (fixed[cur - k]) {
                a[cur] = a[cur - k] + 1 - (pref[cur] - pref[cur - k]);
                if (a[cur] < -1e9) valid = false;
            }
        }
        if (cur + 1 < n) {
            if (fixed[cur + 1]) {
                a[cur] = a[cur + 1] - 1 - (pref[cur + 1] - pref[cur]);
                if (a[cur] < -1e9) valid = false;
            }
        }
        if (cur >= k && cur + 1 < n) {
            a[cur] = max(a[cur], pref[cur] - pref[cur - k] + 1);
            a[cur] = min(a[cur], pref[cur + 1] - pref[cur] - 1);
            if (a[cur] < -1e9 || a[cur] > 1e9) valid = false;
        }
        pref[cur + 1] = pref[cur] + a[cur];
        if (cur + 2 >= k) {
            valid &= check(a, k);
        }
    }
    if (!valid || !check(a, k)) {
        cout << "Incorrect sequence";
        return;
    }
    for (auto x : a) {
        cout << x << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}