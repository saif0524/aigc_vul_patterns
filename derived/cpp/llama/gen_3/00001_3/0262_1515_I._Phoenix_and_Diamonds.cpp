#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll N = 2e5 + 10;

ll n, q;
ll a[N], w[N], v[N];

struct Node {
    ll w, v, num;
    bool operator<(const Node& x) const {
        if (v == x.v) {
            if (w == x.w) return num < x.num;
            return w < x.w;
        }
        return v > x.v;
    }
};

vector<Node> vec;

ll ans;

void solve() {
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> w[i] >> v[i];
    }
    for (ll i = 1; i <= q; i++) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll k, d;
            cin >> k >> d;
            a[d] += k;
        } else if (op == 2) {
            ll k, d;
            cin >> k >> d;
            a[d] -= k;
        } else {
            ll c;
            cin >> c;
            vec.clear();
            for (ll j = 1; j <= n; j++) {
                if (a[j]) {
                    vec.push_back({w[j], v[j], j});
                }
            }
            sort(vec.begin(), vec.end());
            ans = 0;
            for (ll j = 0; j < vec.size(); j++) {
                ll cnt = min(a[vec[j].num], c / vec[j].w);
                ans += cnt * vec[j].v;
                c -= cnt * vec[j].w;
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}