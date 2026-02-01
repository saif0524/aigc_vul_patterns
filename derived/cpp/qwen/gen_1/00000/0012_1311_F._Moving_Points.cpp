#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> x(n), v(n);
    for(auto &xi : x) cin >> xi;
    for(auto &vi : v) cin >> vi;
    vector<pair<double, int>> slopes;
    for(int i = 0; i < n; i++){
        if(v[i] == 0) continue;
        double slope = -static_cast<double>(x[i]) / v[i];
        slopes.emplace_back(slope, i);
    }
    sort(slopes.begin(), slopes.end());
    long long ans = 0;
    for(int i = 0; i + 1 < n; i++){
        long long d = abs(x[i+1] - x[i]);
        if(v[i] == v[i+1]) ans += d;
        else ans += d * (v[i] < v[i+1]);
    }
    int last = 0;
    for(const auto &[slope, index] : slopes){
        ans += abs(x[last] + slope * v[last] - x[index]);
        last = index;
    }
    cout << ans;
}