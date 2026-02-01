#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_reach(ll capacity, ll distance, ll time, const vector<int>& stations) {
    ll required_fuel = 0, last_station = 0;
    for (int station : stations) {
        ll dist = station - last_station;
        ll fuel_used = min(dist, (time / 2) * 1LL);
        fuel_used = min(fuel_used, capacity);
        required_fuel += fuel_used;
        ll remaining_time = time - fuel_used * 2;
        if (remaining_time < ((dist - fuel_used) * 1LL)) {
            return false;
        }
        last_station = station;
    }
    ll remaining_distance = distance - last_station;
    ll fuel_needed = (remaining_distance + 1) / 2;
    return required_fuel + fuel_needed <= capacity;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    ll s, t;
    cin >> n >> k >> s >> t;
    vector<pair<ll, ll>> cars(n);
    for(auto &car: cars) cin >> car.second >> car.first;
    vector<int> gas_stations(k);
    for(auto &gs: gas_stations) cin >> gs;
    sort(gas_stations.begin(), gas_stations.end());
    ll answer = LLONG_MAX;
    for(const auto &[price, capacity]: cars){
        if(can_reach(capacity, s, t, gas_stations)){
            answer = min(answer, price);
        }
    }
    if(answer == LLONG_MAX) cout << -1;
    else cout << answer;
}