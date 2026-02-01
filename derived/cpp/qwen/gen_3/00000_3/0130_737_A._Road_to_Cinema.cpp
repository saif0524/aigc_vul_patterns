#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_reach(int n, int k, ll s, ll t, ll price, ll capacity, vector<ll>& gas_stations) {
    if (capacity * 2 <= s) return false;
    
    gas_stations.push_back(s);
    sort(gas_stations.begin(), gas_stations.end());
    
    ll fuel = capacity;
    ll time_taken = 0;
    ll position = 0;
    
    for (ll gs : gas_stations) {
        ll distance_to_gas = gs - position;
        
        if (distance_to_gas > fuel) return false;
        
        ll fuel_needed_to_get_there = distance_to_gas;
        ll time_to_get_there_normal = distance_to_gas * 2;
        ll time_to_get_there_accel = distance_to_gas;
        
        if (time_taken + time_to_get_there_normal <= t) {
            position = gs;
            fuel -= fuel_needed_to_get_there;
            time_taken += time_to_get_there_normal;
            continue;
        }
        
        ll fuel_spent_accel = (t - time_taken) / 2;
        if (fuel_spent_accel * 2 > fuel) {
            fuel_spent_accel = fuel / 2;
        }
        
        ll distance_covered_accel = fuel_spent_accel;
        ll time_covered_accel = distance_covered_accel;
        position += distance_covered_accel;
        fuel -= fuel_spent_accel * 2;
        time_taken += time_covered_accel;
        
        if (fuel + capacity < gs - position) return false;
        fuel = capacity;
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    ll s, t;
    cin >> n >> k >> s >> t;
    
    vector<pair<ll, ll>> cars(n);
    for(int i=0;i<n;i++){
        cin >> cars[i].first >> cars[i].second;
    }
    
    vector<ll> gas_stations(k);
    for(int i=0;i<k;i++){
        cin >> gas_stations[i];
    }
    
    sort(cars.begin(), cars.end());
    
    ll min_price = -1;
    for(auto car : cars){
        if(can_reach(n, k, s, t, car.first, car.second, gas_stations)){
            min_price = car.first;
            break;
        }
    }
    
    cout << min_price;
}