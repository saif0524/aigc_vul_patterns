#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long k;
    cin >> n >> k >> m;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    map<int, long long> city_count;
    for(auto &x: a) city_count[x] += m;
    long long total = 0;
    for(auto &[city, count]: city_count){
        long long teams = count / k;
        total += count - teams * k;
    }
    cout << total;
    return 0;
}