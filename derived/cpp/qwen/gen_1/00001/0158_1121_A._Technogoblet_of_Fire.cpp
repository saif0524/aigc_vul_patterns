#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> power(n);
    for(auto &x: power) cin >> x;
    vector<int> school(n);
    for(auto &x: school) cin >> x;
    vector<int> chosen(k);
    for(auto &x: chosen) --x, cin >> x;

    vector<int> max_power_in_school(m, 0);
    for(int i = 0; i < n; ++i){
        max_power_in_school[school[i] - 1] = max(max_power_in_school[school[i] - 1], power[i]);
    }
    int ans = 0;
    for(auto &c: chosen){
        if(power[c] != max_power_in_school[school[c] - 1])
            ++ans;
    }
    cout << ans;
}