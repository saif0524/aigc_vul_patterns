#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

ll cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i){
        ll r, w;
        cin >> r >> w;
        points[i] = Point(r - c, w - d);
    }
    sort(points.begin(), points.end());
    vector<Point> hull;
    for(int i = 0; i < n; ++i){
        while(hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), points[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int m = hull.size();
    ll res = 0;
    for(int i = 0; i < m; ++i){
        for(int j = i + 1; j < m; ++j){
            for(int k = j + 1; k < m; ++k){
                if(cross(hull[i], hull[j], hull[k]) < 0){
                    res++;
                }
            }
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < i; ++j){
            for(int k = 0; k < j; ++k){
                if(cross(hull[i], hull[j], hull[k]) < 0){
                    res++;
                }
            }
        }
    }
    cout << res;
}