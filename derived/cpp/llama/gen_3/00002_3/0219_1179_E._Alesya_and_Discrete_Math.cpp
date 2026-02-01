#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

ll n, L, ans[MAXN][2];
vector<pair<int, ll>> vec[MAXN];

ll query(int i, ll x) {
    cout << "? " << i << " " << x << endl;
    ll res;
    cin >> res;
    return res;
}

void solve() {
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = 1000000000000000000LL;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll val = query(i, mid);
            if (val >= L / n) r = mid;
            else l = mid + 1;
        }
        vec[i].push_back(make_pair(i, l));
        ans[i][0] = l;
        ans[i][1] = l + 1;
    }
    sort(vec[1].begin(), vec[1].end());
    cout << "!" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}