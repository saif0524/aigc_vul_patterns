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

bool isInside(Point polygon[], int n, Point p) {
    if (n < 3) return false;

    Point extreme = {1e9, p.y};
    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;

        if (orientation(polygon[i], polygon[next], p) == 0)
            return onSegment(polygon[i], p, polygon[next]);

        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    return count % 2 == 1;
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Point polygon[n];
    for(int i=0;i<n;i++){
        cin >> polygon[i].x >> polygon[i].y;
    }
    int ans = 0;
    for(int x = polygon[0].x; x <= polygon[1].x; x++){
        Point p = {x, polygon[0].y};
        if(!isInside(polygon, n, p)){
            ans++;
        }
    }
    cout << ans;
}