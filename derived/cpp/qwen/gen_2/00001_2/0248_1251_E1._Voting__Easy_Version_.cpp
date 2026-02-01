#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, long long>> vec(n);
        for(auto &p: vec){
            cin >> p.first >> p.second;
        }
        sort(vec.begin(), vec.end());
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0, current = 0;
        for(int i=0;i<n;i++){
            if(current < vec[i].first){
                while(!pq.empty() && current < vec[i].first){
                    current++;
                    ans += pq.top();
                    pq.pop();
                }
            }
            if(current < vec[i].first){
                ans += vec[i].second;
                current++;
            }
            else{
                pq.push(vec[i].second);
            }
        }
        cout << ans << "\n";
    }
}