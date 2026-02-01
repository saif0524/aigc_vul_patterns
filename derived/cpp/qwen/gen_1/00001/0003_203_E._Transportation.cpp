#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ll;

bool compare(const ll &a, const ll &b) {
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, d, S;
    cin >> n >> d >> S;
    vector<ll> cars;
    long long self_drivers = 0;
    long long self_fuel = 0;
    for(long long i=0;i<n;i++){
        long long ci, fi, li;
        cin >> ci >> fi >> li;
        if(li >= d){
            if(ci == 0){
                cars.push_back({fi, -1});
            }
            else{
                cars.push_back({fi, ci});
            }
        }
    }
    sort(cars.begin(), cars.end(), compare);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    long long ans = 0;
    long long fuel_spent = 0;
    long long current_capacity = 0;
    for(auto car : cars){
        if(car.second == -1 && car.first <= S){
            pq.push(car.first);
            fuel_spent += car.first;
            S -= car.first;
            ans++;
        }
        else if(car.second != -1 && car.first <= S){
            pq.push(car.first);
            fuel_spent += car.first;
            S -= car.first;
            current_capacity += car.second;
            ans++;
        }
        while(!pq.empty() && current_capacity < ans){
            long long top = pq.top();
            pq.pop();
            S += top;
            fuel_spent -= top;
            current_capacity++;
            ans--;
        }
    }
    cout << ans << " " << fuel_spent;
}