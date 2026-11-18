#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = LLONG_MAX;
    for(int i=0;i<=k;i++){
        long long sum = 0;
        for(int j=0;j<n;j++){
            if(j<i || j>=n-(k-i)){
                sum += abs(a[j] - a[(j+i)%n]);
            }
        }
        ans = min(ans, sum);
    }
    cout << ans;
}