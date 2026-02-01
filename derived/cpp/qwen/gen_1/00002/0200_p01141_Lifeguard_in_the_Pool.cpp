#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAX = 12;
const ld EPS = 1e-10;

ld sqr(ld x) { return x * x; }
ld dist(ld x1, ld y1, ld x2, ld y2) { return sqrt(sqr(x1 - x2) + sqr(y1 - y2)); }

bool inPolygon(const vector<pair<ld, ld>>& poly, ld x, ld y) {
    int n = poly.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        auto [x1, y1] = poly[i];
        auto [x2, y2] = poly[j];
        if(y1 == y2 && (y - y1) * (x - x1) * (x - x2) <= 0 && min(x1, x2) <= x && x <= max(x1, x2)) return true;
        if(y < y1 + EPS != y < y2 + EPS) {
            if((y - y1) * (x2 - x1) < (y2 - y1) * (x - x1) + EPS) cnt++;
            if(y1 > y2 && (x - x1) * (y2 - y1) <= (x2 - x1) * (y - y1) + EPS) cnt--;
        }
    }
    return cnt != 0;
}

ld minTime(const vector<pair<ld, ld>>& poly, ld tg, ld tw, ld xs, ld ys, ld xt, ld yt) {
    ld mind = 1e18;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        auto [x1, y1] = poly[i];
        auto [x2, y2] = poly[j];
        ld d1 = dist(xs, ys, x1, y1);
        ld d2 = dist(xs, ys, x2, y2);
        ld mx = (x1 == x2) ? x1 : max(x1, x2);
        ld mn = (x1 == x2) ? x1 : min(x1, x2);
        ld my = (y1 == y2) ? y1 : max(y1, y2);
        ld ny = (y1 == y2) ? y1 : min(y1, y2);
        if((x1 == x2) && mn <= xt + EPS && xt <= mx + EPS) {
            mind = min(mind, d1 + tw * dist(xt, yt, x1, ys) + tg * (abs(xs - x1)));
            mind = min(mind, d2 + tw * dist(xt, yt, x2, ys) + tg * (abs(xs - x2)));
        } else if((y1 == y2) && ny <= yt + EPS && yt <= my + EPS) {
            mind = min(mind, d1 + tw * dist(xt, yt, xs, y1) + tg * (abs(ys - y1)));
            mind = min(mind, d2 + tw * dist(xt, yt, xs, y2) + tg * (abs(ys - y2)));
        } else {
            ld t = (x2 - x1 != 0) ? (xt - x1) / (x2 - x1) : (yt - y1) / (y2 - y1);
            ld px = x1 + t * (x2 - x1);
            ld py = y1 + t * (y2 - y1);
            if((x1 == x2 && (xt < mn - EPS || xt > mx + EPS)) || (y1 == y2 && (yt < ny - EPS || yt > my + EPS)) || (t < 0 - EPS) || (t > 1 + EPS)) {
                mind = min(mind, d1 + tw * dist(xt, yt, x1, ys));
                mind = min(mind, d2 + tw * dist(xt, yt, x2, ys));
            } else {
                mind = min(mind, d1 + tg * dist(xs, ys, px, py) + tw * dist(px, py, xt, yt));
                mind = min(mind, d2 + tg * dist(xs, ys, px, py) + tw * dist(px, py, xt, yt));
            }
        }
    }
    return mind;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        while(cin >> n){
                if(n == 0) break;
                vector<pair<ld, ld>> poly(n);
                for(int i=0;i<n;i++)
                        cin >> poly[i].first >> poly[i].second;
                ld tg, tw;
                cin >> tg >> tw;
                ld xs, ys, xt, yt;
                cin >> xs >> ys >> xt >> yt;
                if(inPolygon(poly, xs, ys)){
                        ld ans = 0;
                        for(auto [x, y] : poly)
                                ans = max(ans, dist(x, y, xt, yt));
                        ans *= tw;
                        cout << fixed << setprecision(12) << ans << "\n";
                }else if(inPolygon(poly, xt, yt)){
                        ld ans = minTime(poly, tg, tw, xs, ys, xt, yt);
                        cout << fixed << setprecision(12) << ans << "\n";
                }else{
                        cout << "Error: Both points should be either inside or outside the polygon\n";
                }
        }
}