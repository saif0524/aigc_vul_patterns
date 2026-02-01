#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Segment {
    ll l, r;
};

bool operator<(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

bool can_jump(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    map<ll, vector<Segment>> rows;
    for(int i=0;i<n;i++){
        ll r, a, b;
        cin >> r >> a >> b;
        rows[r].emplace_back(Segment{a,b});
    }
    set<pair<ll, ll>> q;
    q.emplace(0, x0*1000000000+y0);
    map<pair<ll, ll>, ll> dist;
    dist[{x0, y0}] = 0;
    while(!q.empty()){
        auto [d, pos] = *q.begin();
        q.erase(q.begin());
        ll x = pos / 1000000000, y = pos % 1000000000;
        if(x == x1 && y == y1){
            cout << d;
            return 0;
        }
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(dx == 0 && dy == 0) continue;
                ll nx = x + dx, ny = y + dy;
                if(rows.find(nx) != rows.end()){
                    auto& segments = rows[nx];
                    int idx = lower_bound(segments.begin(), segments.end(), Segment{ny, ny}) - segments.begin();
                    if(idx < segments.size() && ny <= segments[idx].r){
                        if(dist.find({nx, ny}) == dist.end() || dist[{nx, ny}] > d + 1){
                            dist[{nx, ny}] = d + 1;
                            q.emplace(d + 1, nx*1000000000+ny);
                        }
                    }
                    if(idx > 0 && ny >= segments[idx-1].l){
                        if(dist.find({nx, ny}) == dist.end() || dist[{nx, ny}] > d + 1){
                            dist[{nx, ny}] = d + 1;
                            q.emplace(d + 1, nx*1000000000+ny);
                        }
                    }
                }
            }
        }
    }
    cout << -1;
}