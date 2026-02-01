#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
};

struct Meteor {
    ll t1, t2;
    Point p1, p2;
};

ll crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

bool isParallel(const Meteor& m1, const Meteor& m2) {
    Point v1 = m1.p2 - m1.p1;
    Point v2 = m2.p2 - m2.p1;
    return crossProduct(v1, v2) == 0;
}

bool isCollinear(const Meteor& m1, const Meteor& m2) {
    Point v1 = m1.p2 - m1.p1;
    Point v2 = m2.p1 - m1.p1;
    return crossProduct(v1, v2) == 0;
}

bool doesIntersect(const Meteor& m1, const Meteor& m2) {
    if (isParallel(m1, m2)) {
        if (!isCollinear(m1, m2)) return false;
    }
    Point v1 = m1.p2 - m1.p1;
    Point v2 = m2.p2 - m2.p1;
    Point v3 = m1.p1 - m2.p1;
    Point v4 = m1.p1 - m2.p2;
    ll d1 = crossProduct(v1, v3);
    ll d2 = crossProduct(v1, v4);
    ll d3 = crossProduct(v2, v3);
    ll d4 = crossProduct(v2, v4);
    if (d1 * d2 < 0 && d3 * d4 < 0) {
        if (m1.t1 == m1.t2) return true;
        if (m2.t1 == m2.t2) return true;
        ll den1 = (m1.p2.x - m1.p1.x) * (m2.p1.y - m2.p2.y) - (m1.p2.y - m1.p1.y) * (m2.p1.x - m2.p2.x);
        ll num1 = (m1.p1.x - m2.p1.x) * (m2.p1.y - m2.p2.y) - (m1.p1.y - m2.p1.y) * (m2.p1.x - m2.p2.x);
        ll num2 = (m1.p1.x - m2.p1.x) * (m1.p2.y - m1.p1.y) - (m1.p1.y - m2.p1.y) * (m1.p2.x - m1.p1.x);
        ll t = num1 * (m2.t2 - m2.t1);
        ll s = num2 * (m1.t2 - m1.t1);
        return (t % den1 == 0 && s % den1 == 0);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Meteor> meteors(n);
    for(auto &m: meteors){
        cin >> m.t1 >> m.p1.x >> m.p1.y >> m.t2 >> m.p2.x >> m.p2.y;
    }
    int ans = 1;
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=i+1; j<n; j++){
            if(doesIntersect(meteors[i], meteors[j])){
                count++;
            }
        }
        ans = max(ans, count);
    }
    cout << ans;
}