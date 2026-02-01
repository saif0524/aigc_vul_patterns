#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for(auto &a: A) cin >> a;
    sort(A.begin(), A.end());
    long long ans = LLONG_MAX;
    for(int i = 0; i <= k; ++i){
        long long current = 0;
        for(int j = 0; j < n; ++j){
            if(j < i){
                current += abs(A[j] - A[i]);
            }else{
                current += abs(A[j] - A[n-k+i-1]);
            }
        }
        ans = min(ans, current);
    }
    cout << ans;
}