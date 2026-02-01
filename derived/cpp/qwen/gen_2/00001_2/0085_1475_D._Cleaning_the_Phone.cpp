#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n), b(n);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        vector<pair<long long, long long>> apps(n);
        for(int i = 0; i < n; ++i){
            apps[i] = {a[i], b[i]};
        }
        sort(apps.begin(), apps.end(), [&](auto &p1, auto &p2){
            return p1.first > p2.first;
        });
        long long max_convenience = 0;
        for(auto &p : apps){
            max_convenience += p.second;
        }
        vector<long long> psum(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            psum[i] = psum[i - 1] + apps[i - 1].second;
        }
        long long minloss = -1;
        long long left = 0, right = 0, currentsum = 0;
        while(left <= right && right <= n){
            if(currentsum >= m){
                minloss = min(minloss, max_convenience - psum[left] + psum[right]);
                currentsum -= apps[left++].first;
            }
            else{
                if(right < n) currentsum += apps[right++].first;
                else break;
            }
        }
        cout << minloss << "\n";
    }
}