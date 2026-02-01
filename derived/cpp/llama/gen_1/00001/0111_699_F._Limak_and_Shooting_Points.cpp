#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1010;

struct Point {
    ll x, y;
    int id;
    char type;

    bool operator<(const Point &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return id < other.id;
    }
};

bool cmp(const Point &p1, const Point &p2) {
    if (p1.x == p2.x) {
        if (p1.y == p2.y) return p1.id < p2.id;
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int n, k;
Point pts[MAXN + MAXN];
ll slope[MAXN][MAXN];
bool fear[MAXN];

int cnt(ptrdiff_t index, const Point &p) {
    int begin = index, end = begin + n;
    int cnt = 0;
    for (int i = begin; i < end; ++i) {
        if (pts[i].type == 'M' && slope[p.id][pts[i].id] > 0) ++cnt;
    }
    return cnt;
}

void solve() {
    cin >> k >> n;
    for (int i = 0; i < k + n; ++i) {
        cin >> pts[i].x >> pts[i].y;
        if (i < k) pts[i].type = 'S';
        else pts[i].type = 'M';
        pts[i].id = i;
    }

    sort(pts, pts + k + n, cmp);

    for (int i = 0; i < k + n; ++i) {
        for (int j = i + 1; j < k + n; ++j) {
            if (pts[i].x == pts[j].x) {
                slope[pts[i].id][pts[j].id] = pts[i].y <= pts[j].y;
            } else {
                slope[pts[i].id][pts[j].id] = (pts[j].x - pts[i].x) * (pts[i].y - pts[j].y) <= 0;
            }
        }
    }

    memset(fear, false, sizeof fear);

    for (int mask = 0; mask < (1 << k); ++mask) {
        bool mark[n];
        memset(mark, false, sizeof mark);
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                for (int j = k; j < k + n; ++j) {
                    if (!mark[pts[j].id - k] && slope[pts[i].id][pts[j].id]) mark[pts[j].id - k] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mark[i]) fear[i] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (fear[i]) ++ans;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}