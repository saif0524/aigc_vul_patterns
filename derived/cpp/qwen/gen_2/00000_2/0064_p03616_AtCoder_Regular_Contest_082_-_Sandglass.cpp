#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long X, K;
    cin >> X >> K;
    vector<long long> r(K);
    for(auto &x: r) cin >> x;
    long long Q;
    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    for(auto &x: queries) cin >> x.first >> x.second;
    r.push_back(1e18);
    int pos = 0;
    for(int i = 0; i < Q; i++){
        long long t = queries[i].first;
        long long a = queries[i].second;
        while(pos < K && r[pos] <= t){
            if(pos%2 == 0) a = max(0LL, a - (r[pos] - (pos == 0 ? 0 : r[pos-1])));
            else a = min(X, a + (r[pos] - (pos == 0 ? 0 : r[pos-1])));
            pos++;
        }
        if(pos%2 == 0) a = max(0LL, a - (t - (pos == 0 ? 0 : r[pos-1])));
        else a = min(X, a + (t - (pos == 0 ? 0 : r[pos-1])));
        cout << a << "\n";
    }
}