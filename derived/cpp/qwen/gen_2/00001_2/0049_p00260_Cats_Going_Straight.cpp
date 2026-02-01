#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Point {
    ll x, y;
};

ll cross(Point &O, Point &A, Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool insideOrOnBoundary(Point &P, vector<Point> &pol) {
    int n = pol.size();
    bool on = false;
    for(int i = 0, j = n - 1; i < n; j = i++) {
        if(P.x == pol[i].x && P.y == pol[i].y) return true;
        if(((pol[i].y > P.y) != (pol[j].y > P.y)) && 
           (P.x < (pol[j].x - pol[i].x) * (P.y - pol[i].y) / (pol[j].y - pol[i].y) + pol[i].x))
            on = !on;
    }
    return on;
}

bool inTriangle(Point &P, Point &A, Point &B, Point &C) {
    ll d1 = cross(P, A, B);
    ll d2 = cross(P, B, C);
    ll d3 = cross(P, C, A);
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos) && insideOrOnBoundary(P, {A, B, C});
}

bool allInside(vector<Point> &pol, vector<Point> &chosen) {
    for(auto &p : pol) {
        bool inside = false;
        for(int i = 0; i < chosen.size(); ++i) {
            for(int j = i + 1; j < chosen.size(); ++j) {
                for(int k = j + 1; k < chosen.size(); ++k) {
                    if(inTriangle(p, chosen[i], chosen[j], chosen[k])) {
                        inside = true;
                        break;
                    }
                }
                if(inside) break;
            }
            if(inside) break;
        }
        if(!inside) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<Point> pol(n);
        for(auto &p : pol) cin >> p.x >> p.y;
        int ans = n;
        for(int mask = 0; mask < (1 << n); ++mask) {
            if(__builtin_popcount(mask) < ans) {
                vector<Point> chosen;
                for(int i = 0; i < n; ++i) if(mask & (1 << i)) chosen.push_back(pol[i]);
                if(allInside(pol, chosen)) ans = chosen.size();
            }
        }
        cout << ans << "\n";
    }
}