#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll orientation(Point p, Point q, Point r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool isInsidePolygon(Point polygon[], int n, Point p) {
    if (n < 3) return false;
    Point extreme = {1e10, p.y};
    int count = 0;
    int i = 0;
    do {
        int next = (i + 1) % n;
        if (orientation(polygon[i], polygon[next], p) == 0) {
            if (p.x <= max(polygon[i].x, polygon[next].x) && p.x >= min(polygon[i].x, polygon[next].x) &&
                p.y <= max(polygon[i].y, polygon[next].y) && p.y >= min(polygon[i].y, polygon[next].y)) {
                return true;
            }
            return false;
        }
        if (orientation(polygon[i], p, extreme) == 2) {
            int o2 = orientation(polygon[next], p, extreme);
            if (o2 == 1) count++;
        } else {
            int o2 = orientation(polygon[next], p, extreme);
            if (o2 == 2) count++;
        }
        i = next;
    } while (i != 0);
    return count & 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Point points[n];
    for(int i=0;i<n;i++) cin >> points[i].x >> points[i].y;
    Point A = points[0], B = points[1];
    int ans=0;
    for(ll x=min(A.x,B.x);x<=max(A.x,B.x);x++){
        Point p = {x, A.y};
        if(!isInsidePolygon(points, n, p)) ans++;
    }
    cout << ans;
}