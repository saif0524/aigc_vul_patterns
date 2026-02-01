#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld A, B, C, D;
ld X[10005], Y[10005], A0[10005], W[10005];

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return hypot(x2 - x1, y2 - y1);
}

bool can(ld v, int k, int n) {
    priority_queue<ld> pq;
    for(int i = 0; i < n; ++i) {
        ld dist_to_line = abs(A * X[i] + B * Y[i] + C) / dist(A, B, 0, 1);
        ld t_min = dist_to_line / v;
        ld t_max = (dist(X[i], Y[i], A, B) + dist(X[i], Y[i], C, D)) / v;
        ld angle = atan2(B * X[i] - A * Y[i] - A * B, C * X[i] + B * Y[i] - B * C);
        while(angle < 0) angle += 2 * M_PI;
        ld diff = abs(angle - A0[i]);
        if(diff > M_PI) diff = 2 * M_PI - diff;
        ld time_to_rotate = diff / W[i];
        if(t_min + time_to_rotate > t_max) continue;
        pq.push(-(t_min + time_to_rotate));
        if(pq.size() > k) pq.pop();
    }
    return pq.size() < k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C >> D;
    ld dx = C-A;
    ld dy = D-B;
    A = -dy;
    B = dx;
    C = -(A*A + B*B);
    int n;
    cin >> n;
    for(int i = 0;i < n; i++) cin >> X[i] >> Y[i] >> A0[i] >> W[i];
    int k;
    cin >> k;
    ld lo = 0, hi = 1e6;
    for(int iter = 0;iter < 100; iter++){
        ld mid = (lo + hi) / 2;
        if(can(mid, k, n)) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(9) << hi;
}