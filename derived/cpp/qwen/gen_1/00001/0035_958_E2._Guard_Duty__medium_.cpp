#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, N;
    cin >> K >> N;
    vector<int> t(N);
    for(auto &i: t) cin >> i;
    sort(t.begin(), t.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; ++i){
        if(pq.size() < K){
            pq.push(t[i]);
        }
        else{
            int x = pq.top();
            pq.pop();
            pq.push(t[i] - x);
        }
    }
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}