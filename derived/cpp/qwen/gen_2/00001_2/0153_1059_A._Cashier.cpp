#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long L, a;
    cin >> n >> L >> a;
    vector<pair<long long, long long>> customers(n);
    for(auto &c : customers) cin >> c.first >> c.second;
    
    long long free_time = L, last_end = 0;
    for(auto &c : customers){
        free_time -= (c.first - last_end);
        last_end = c.first + c.second;
    }
    free_time -= (L - last_end);
    
    long long breaks = free_time / a;
    cout << breaks;
}