#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxn = 200005;
int n;
int P[2];
pair<int, int> a[maxn];

ld sqr(ld x) {
    return x * x;
}

ld dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(sqr(b.first - a.first) + sqr(b.second - a.second));
}

const ld pi = acos(-1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> P[0] >> P[1];
    ld minr = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ld d = dist({P[0], P[1]}, {a[i].first, a[i].second});
        minr = min(minr, d);
    }
    cout.precision(20);
    cout << fixed << pi * minr * minr << endl;
    return 0;
}