#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> servers(n);
    for(int i=0; i<n; ++i){
        servers[i] = {0, i+1};
    }
    for(int i=0; i<q; ++i){
        int t, k, d;
        cin >> t >> k >> d;
        sort(servers.begin(), servers.end());
        int count = 0;
        int sum = 0;
        for(auto &s : servers){
            if(s.first <= t){
                s.first = t + d;
                sum += s.second;
                if(++count == k) break;
            }
        }
        if(count == k) cout << sum << "\n";
        else cout << "-1\n";
    }
}