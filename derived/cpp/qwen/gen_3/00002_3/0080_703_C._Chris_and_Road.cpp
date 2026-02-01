#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const db EPS = 1e-8;

struct pt {
    db x, y;
    pt() : x(0), y(0) {}
    pt(db x, db y) : x(x), y(y) {}
    pt operator+(pt p) { return pt(x+p.x, y+p.y); }
    pt operator-(pt p) { return pt(x-p.x, y-p.y); }
    pt operator*(db c) { return pt(x*c, y*c); }
    pt operator/(db c) { return pt(x/c, y/c); }
};

db dot(pt p, pt q) { return p.x*q.x+p.y*q.y; }
db dist2(pt p, pt q) { return dot(p-q,p-q); }

int n, w, v, u;
pt bus[10010];

db check(db t) {
    pt target(0, w);
    db lo = 0, hi = w;
    for(int i = 0; i < n; i++) {
        pt a = bus[i]-pt(v*t,0);
        pt b = bus[(i+1)%n]-pt(v*t,0);
        if(min(a.y, b.y) > lo) lo = min(a.y, b.y);
        if(max(a.y, b.y) < hi) hi = max(a.y, b.y);
    }
    return hi-lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> v >> u;
    for(int i=0;i<n;i++) cin >> bus[i].x >> bus[i].y;
    db lo = 0, hi = 1e9;
    while(hi-lo > EPS) {
        db mid = (lo+hi)/2;
        if(check(mid) > 0) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << (w/lo)/u;
}