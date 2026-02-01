#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    vector<int> pos_a(n+1);
    for(int i=0; i<n; ++i) pos_a[a[i]] = i;
    vector<int> res(n, INT_MAX);
    vector<int> min_dist(n, INT_MAX);
    for(int i=0; i<n; ++i){
        int idx_a = pos_a[b[i]];
        int idx_b = i;
        for(int offset: {0, n}){
            int rel_pos = (idx_a - (idx_b + offset) + n) % n;
            min_dist[rel_pos] = min(min_dist[rel_pos], abs(idx_a - (idx_b + offset)));
        }
    }
    for(int i=0; i<n; ++i) res[(n-i)%n] = min_dist[i];
    for(int i=0; i<n; ++i) cout << res[i] << (i==n-1?'\n':' ');
}