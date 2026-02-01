#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    auto is_bad = [&](ll x, ll y){
        return (abs(x + y) % (1LL << a) == 0) || (abs(x - y) % (1LL << b) == 0);
    };
    ll ans = LLONG_MAX;
    for(ll dx = -1; dx <= 1; dx++){
        for(ll dy = -1; dy <= 1; dy++){
            if(abs(dx) + abs(dy) > 1) continue;
            ll cx = x1 + dx, cy = y1 + dy;
            if(is_bad(cx, cy)){
                ll steps = abs(cx - x2) + abs(cy - y2);
                ans = min(ans, steps + 1);
            }
        }
    }
    if(ans == LLONG_MAX) ans = 0;
    cout << ans;
}