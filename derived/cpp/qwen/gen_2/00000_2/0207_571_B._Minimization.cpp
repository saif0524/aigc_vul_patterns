#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    long long ans = LLONG_MAX;
    for(int i=0; i<=k; i++){
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;
        for(int j=0; j<n; j++){
            if(j < i || j >= n - (k - i)) pq.push(a[j]);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            sum += a[j];
        }
        ans = min(ans, sum);
    }
    cout << ans;
}