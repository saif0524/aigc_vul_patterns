#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

typedef long long ll;

const int MAXN = 1001;
const int MAXQ = 200001;

ll N, L;
ll left[MAXN], right[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll query(ll i, ll x) {
    cout << "?" << " " << i + 1 << " " << x << endl;
    ll ret;
    cin >> ret;
    return ret;
}

void solve() {
    cin >> N >> L;
    vector<ll> pts;
    pts.push_back(0);
    for (int i = 0; i < N; i++) {
        ll l = 0, r = 1e18, m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            ll v = query(i, m);
            if (v >= L / N) r = m;
            else l = m;
        }
        pts.push_back(r);
    }
    pts.push_back(1e18);
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<pair<ll, vector<int>>> ranges;
    for (int i = 0; i < N; i++) {
        vector<int> candidates;
        for (int j = 0; j < pts.size() - 1; j++) {
            ll v1 = query(i, pts[j]);
            ll v2 = query(i, pts[j + 1]);
            if (v2 - v1 >= L / N) candidates.push_back(j);
        }
        sort(candidates.begin(), candidates.end(), [&](int x, int y) {
            ll v1 = query(i, pts[x]);
            ll v2 = query(i, pts[x + 1]);
            ll v3 = query(i, pts[y]);
            ll v4 = query(i, pts[y + 1]);
            return v2 - v1 < v4 - v3;
        });
        while (candidates.size() > 10) candidates.pop_back();
        ll best = -1;
        ll bestval = -1;
        for (int j : candidates) {
            ll v1 = query(i, pts[j]);
            ll v2 = query(i, pts[j + 1]);
            if (v2 - v1 > bestval) {
                best = j;
                bestval = v2 - v1;
            }
        }
        ranges.push_back({i, {best}});
    }

    sort(ranges.begin(), ranges.end(), [&](pair<ll, vector<int>> &a, pair<ll, vector<int>> &b) {
        ll v1 = query(a.first, pts[a.second[0]]);
        ll v2 = query(a.first, pts[a.second[0] + 1]);
        ll v3 = query(b.first, pts[b.second[0]]);
        ll v4 = query(b.first, pts[b.second[0] + 1]);
        return v1 < v3;
    });

    for (auto &i : ranges) {
        left[i.first] = pts[i.second[0]];
        right[i.first] = pts[i.second[0] + 1];
    }

    cout << "!" << endl;
    for (int i = 0; i < N; i++) {
        cout << left[i] << " " << right[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}