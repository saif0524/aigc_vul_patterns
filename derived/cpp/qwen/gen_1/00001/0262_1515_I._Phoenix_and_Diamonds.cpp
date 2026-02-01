#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> diamonds(n);
    vector<int> count(n);
    for(int i=0; i<n; i++){
        int a, w, v;
        cin >> a >> w >> v;
        count[i] = a;
        diamonds[i].emplace_back(a, w);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    auto process = [&](int i){
        int have = count[i];
        for(int j=0; j<diamonds[i].size(); j++){
            auto [a, w] = diamonds[i][j];
            if(a > have){
                diamonds[i][j] = {have, w};
                pq.emplace(w, i);
                return;
            }
            have -= a;
        }
        if(have > 0){
            diamonds[i].emplace_back(have, diamonds[i].back().second);
            pq.emplace(diamonds[i].back().second, i);
        }
    };
    for(int i=0; i<n; i++){
        if(count[i] > 0){
            pq.emplace(diamonds[i].back().second, i);
        }
    }
    while(q--){
        int t;
        cin >> t;
        if(t==1 || t==2){
            int k, d;
            cin >> k >> d;
            d--;
            if(t==1){
                count[d] += k;
                diamonds[d].emplace_back(k, diamonds[d].back().second);
            }
            else{
                count[d] -= k;
                while(diamonds[d].size() > 0 && diamonds[d].back().first > k){
                    k -= diamonds[d].back().first;
                    diamonds[d].pop_back();
                }
                if(diamonds[d].size() > 0 && diamonds[d].back().first == k){
                    diamonds[d].pop_back();
                }
                else{
                    diamonds[d].back().first -= k;
                }
            }
            if(count[d] > 0 && diamonds[d].size() > 0){
                pq.emplace(diamonds[d].back().second, d);
            }
            else{
                while(!pq.empty() && pq.top().second == d){
                    pq.pop();
                }
            }
        }
        else{
            long long c;
            cin >> c;
            priority_queue<pair<int, pair<int,int>>> pq2;
            vector<bool> visited(n, false);
            while(!pq.empty()){
                int w, i;
                tie(w, i) = pq.top();
                pq.pop();
                if(visited[i]) continue;
                visited[i] = true;
                int have = count[i];
                for(auto [a, _w] : diamonds[i]){
                    if(have == 0) break;
                    if(a > have) a = have;
                    pq2.emplace(-_w, make_pair(a, _w));
                    have -= a;
                }
            }
            long long ans = 0;
            while(!pq2.empty()){
                int _w;
                int a, w;
                tie(_w, tie(a, w)) = pq2.top();
                pq2.pop();
                if(c >= w){
                    long long take = min(1LL*a, c/w);
                    ans += take * (-_w);
                    c -= take * w;
                }
            }
            cout << ans << "\n";
        }
    }
}