#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-10;
const int MAX_N = 55;

struct Parabola {
    ld a, p, q;
};

vector<Parabola> parabolas;
ld W, H;

bool operator<(const Parabola& p1, const Parabola& p2) {
    return p1.p < p2.p;
}

ld f(ld x, const Parabola& par) {
    return par.q + par.a * (x - par.p) * (x - par.p);
}

ld intersect(const Parabola& p1, const Parabola& p2) {
    ld a = p1.a - p2.a;
    ld b = 2 * (p2.p * p2.a - p1.p * p1.a);
    ld c = p1.q - p2.q + p1.p * p1.p * p1.a - p2.p * p2.p * p2.a;
    ld d = b * b - 4 * a * c;
    return (-b + sqrt(d)) / (2 * a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> W >> H >> parabolas;
    sort(parabolas.begin(), parabolas.end());
    vector<pair<Parabola, ld>> active;
    for(auto& par : parabolas) {
        auto it = lower_bound(active.begin(), active.end(), par, [&](const pair<Parabola, ld>& p, const Parabola& par){
            return p.second < par.p;
        });
        if(it != active.end()) {
            ld prevx = it->second;
            ld curx = intersect(par, it->first);
            if(curx < W) {
                ld prevy = f(prevx, it->first);
                ld cury = f(curx, par);
                active.emplace(it, par, curx);
                cout << hypot(curx - prevx, cury - prevy) << "\n";
            }
        }
        if(it != active.begin()) {
            --it;
            ld prevx = it->second;
            ld curx = intersect(par, it->first);
            if(curx < W) {
                ld prevy = f(prevx, it->first);
                ld cury = f(curx, par);
                active.emplace(it, par, curx);
                cout << hypot(curx - prevx, cury - prevy) << "\n";
            }
        }
        if(active.empty() || active.back().second < par.p) {
            active.emplace_back(par, W);
        } else {
            active.back().first = par;
        }
    }
    ld ans = 0;
    for(int i = 0; i + 1 < active.size(); i++) {
        ld x1 = active[i].second;
        ld x2 = active[i + 1].second;
        ld y1 = f(x1, active[i].first);
        ld y2 = f(x2, active[i + 1].first);
        ans += hypot(x2 - x1, y2 - y1);
    }
    cout << fixed << setprecision(15) << ans + W << "\n";
    return 0;
}