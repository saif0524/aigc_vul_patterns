#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_reach(ll v, ll s, ll t, int k, set<int> &gas_stations) {
    ll fuel = v;
    ll time_spent = 0;
    ll pos = 0;

    while (pos < s) {
        ll next_gas = s;
        auto it = gas_stations.upper_bound(pos);
        if (it != gas_stations.end()) {
            next_gas = *it;
        }

        ll dist_to_next_gas = next_gas - pos;
        ll dist_to_cinema = s - pos;

        ll max_normal_dist = fuel;
        ll max_accel_dist = fuel / 2;

        if (time_spent + dist_to_cinema * 2 <= t) {
            return true;
        }

        if (dist_to_next_gas <= max_accel_dist) {
            pos += dist_to_next_gas;
            fuel -= dist_to_next_gas * 2;
            time_spent += dist_to_next_gas;
        } else if (dist_to_next_gas <= max_normal_dist) {
            pos += dist_to_next_gas;
            fuel -= dist_to_next_gas;
            time_spent += dist_to_next_gas * 2;
        } else {
            ll accel_dist = max_accel_dist;
            ll normal_dist = dist_to_next_gas - accel_dist;
            pos += dist_to_next_gas;
            fuel -= accel_dist * 2 + normal_dist;
            time_spent += accel_dist + normal_dist * 2;
        }

        if (fuel == 0) {
            auto it = gas_stations.lower_bound(pos);
            if (it == gas_stations.end() || *it > s) {
                return false;
            }
            pos = *it;
            fuel = v;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pair<ll, ll>> cars;
    for(int i=0;i<n;i++){
        ll c, v;
        cin >> c >> v;
        cars.push_back({c, v});
    }
    set<int> gas_stations;
    for(int i=0;i<k;i++){
        int g;
        cin >> g;
        gas_stations.insert(g);
    }

    sort(cars.begin(), cars.end());

    ll ans = -1;
    for(auto &[c, v] : cars){
        if(can_reach(v, s, t, k, gas_stations)){
            ans = c;
            break;
        }
    }

    cout << ans;
}