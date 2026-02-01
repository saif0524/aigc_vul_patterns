#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long E, T;
    cin >> N >> E >> T;
    vector<long long> x(N);
    for(auto &i: x) cin >> i;
    long long ans = 0;
    for(int i=0;i<N;i++){
        ans = max(ans, x[i] + T);
        if(i+1 < N){
            ans = max(ans, (x[i+1] + x[i])/2);
        }
    }
    ans = max(ans, x.back() + T);
    ans = max(ans, E);
    cout << ans;
}