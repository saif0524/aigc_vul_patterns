#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, L, step, min_val[1005], max_val[1005];

ll ask(ll func, ll x) {
    cout << "? " << func + 1 << " " << x << endl;
    fflush(stdout);
    ll val;
    cin >> val;
    return val;
}

pair<ll, ll> find_segment(ll func) {
    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (ask(func, mid) == min_val[func]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ll start = l;
    l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (ask(func, mid) < max_val[func]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ll end = l;
    return {start, end};
}

int main(){
    cin >> n >> L;
    step = L / n;
    for (ll i = 0; i < n; i++) {
        min_val[i] = ask(i, 0);
        max_val[i] = ask(i, 1e18);
    }
    vector<pair<ll, ll>> segments;
    for (ll i = 0; i < n; i++) {
        segments.push_back(find_segment(i));
    }
    cout << "!" << endl;
    for (auto [l, r] : segments) {
        cout << l << " " << r << endl;
    }
    return 0;
}