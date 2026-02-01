#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef struct { int x, y; } vec;

const int N = 401;

int rotate(vec &v, int t, vec home) {
    int ans = 0;
    while(t--) {
        swap(v.x, v.y);
        v.x *= -1;
        ans += 1;
    }
    return ans;
}

double dist(vec a, vec b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int solve(vec a[4], vec home[4]) {
    vector<pair<vec, int>> pts;
    for(int i = 0; i < 4; ++i) {
        pts.push_back({a[i], i});
    }

    int ans = 10000;
    do {
        bool ok = true;
        vector<vec> orig;
        for(int i = 0; i < 4; ++i) {
            orig.push_back(pts[i].first);
        }

        vector<int> moves(4, 0);
        for(int t = 0; t <= 3; ++t) {
            for(int i = 0; i < 4; ++i) {
                rotate(a[i], t, home[pts[i].second]);
            }
            double d1 = dist(a[0], a[1]);
            double d2 = dist(a[0], a[2]);
            double d3 = dist(a[0], a[3]);
            double d4 = dist(a[1], a[2]);
            double d5 = dist(a[1], a[3]);
            double d6 = dist(a[2], a[3]);

            if(d1 == d2 && d1 == d3 && d1 == d4 && d1 == d5 && d1 == d6 && d1 > 0) {
                ans = min(ans, t + moves[0] + moves[1] + moves[2] + moves[3]);
                ok = false;
            }
            for(int i = 0; i < 4; ++i) {
                a[i] = orig[i];
            }
            moves[pts[0].second] += 1;
        }
        if(ok) return -1;
    } while(next_permutation(pts.begin(), pts.end()));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        vec a[4], home[4];
        for(int i = 0; i < 4; ++i) {
            cin >> a[i].x >> a[i].y >> home[i].x >> home[i].y;
        }
        cout << solve(a, home) << "\n";
    }

    return 0;
}