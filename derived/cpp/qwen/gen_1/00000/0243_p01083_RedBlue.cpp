#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld EPS = 1e-8;

struct Point {
    ld x, y;
    Point operator-(const Point &p) const { return {x - p.x, y - p.y}; }
    ld norm() const { return x * x + y * y; }
    ld abs() const { return sqrtl(norm()); }
};

ld cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

bool intersect(const Point &a1, const Point &a2, const Point &b1, const Point &b2) {
    ld c1 = cross(a2 - a1, b1 - a1);
    ld c2 = cross(a2 - a1, b2 - a1);
    return (c1 * c2 < -EPS);
}

bool valid_point(const Point &p, const Point &c, ld r) {
    return (p - c).norm() > r * r + EPS;
}

ld solve(const Point &r, const Point &b, const Point &c1, ld r1, const Point &c2, ld r2) {
    if (!valid_point(r, c1, r1) || !valid_point(b, c1, r1) || !valid_point(r, c2, r2) || !valid_point(b, c2, r2))
        return 1e18;
    if (intersect(r, b, c1 - Point{r1, r1}, c1 + Point{r1, r1}) || intersect(r, b, c2 - Point{r2, r2}, c2 + Point{r2, r2}))
        return 1e18;
    Point mid = {(r.x + b.x) / 2, (r.y + b.y) / 2};
    ld dist = (r - b).abs();
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Point c1, c2;
    ld r1, r2;
    cin >> c1.x >> c1.y >> r1 >> c2.x >> c2.y >> r2;
    vector<Point> red(n), blue(n);
    for(int i=0;i<n;i++) cin >> red[i].x >> red[i].y;
    for(int i=0;i<n;i++) cin >> blue[i].x >> blue[i].y;
    vector<vector<ld>> dist(n, vector<ld>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = solve(red[i], blue[j], c1, r1, c2, r2);
            if(dist[i][j] > 1e17) dist[i][j] = 1e18;
        }
    }
    vector<vector<ld>> dp(1<<n, vector<ld>(n, 1e18));
    for(int i=0;i<n;i++) dp[1<<i][i] = dist[0][i];
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))) continue;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)) continue;
                dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], dp[mask][i] + dist[i][j]);
            }
        }
    }
    ld ans = *min_element(dp[(1<<n)-1].begin(), dp[(1<<n)-1].end());
    if(ans > 1e17) cout << "Impossible";
    else cout << fixed << setprecision(10) << ans;
}