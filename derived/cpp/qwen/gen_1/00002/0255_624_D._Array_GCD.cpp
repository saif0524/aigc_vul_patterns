#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    auto check = [&](int val) -> bool{
        int cnt = 0;
        for(auto x: arr){
            cnt += (x%val);
        }
        return cnt < 2;
    };
    auto solve = [&](int val) -> ll{
        int cnt = 0;
        for(auto x: arr){
            cnt += (x%val);
        }
        if(cnt == 0) return 0;
        else if(cnt == 1){
            int idx = -1;
            for(int i=0;i<n;i++){
                if(arr[i] % val == 1){
                    idx = i;
                    break;
                }
            }
            ll cost1 = 1LL*(n-1)*a;
            ll cost2 = 1LL*b;
            ll cost3 = 1LL*a*(idx);
            ll cost4 = 1LL*a*(n-idx-1);
            return min({cost1, cost2, cost3+b, cost4+b});
        }
        else{
            int idx1 = -1, idx2 = -1;
            for(int i=0;i<n;i++){
                if(arr[i] % val == 1){
                    if(idx1 == -1) idx1 = i;
                    else idx2 = i;
                }
            }
            ll cost1 = 1LL*(n-2)*a;
            ll cost2 = 1LL*2*b;
            ll cost3 = 1LL*a*(idx2-idx1-1) + b;
            ll cost4 = 1LL*a*(idx1) + b;
            ll cost5 = 1LL*a*(n-idx2-1) + b;
            ll cost6 = 1LL*a*(idx2) + 1LL*a*(n-idx2-1) + b;
            ll cost7 = 1LL*a*(idx1) + 1LL*a*(idx1+1) + b;
            return min({cost1, cost2, cost3, cost4, cost5, cost6, cost7});
        }
    };
    ll ans = LLONG_MAX;
    for(int val = 2;val<=1000;val++){
        if(check(val)){
            ans = min(ans, solve(val));
        }
    }
    for(int i=0;i<n;i++){
        for(int val = max(2, arr[i]-10);val<=min(1000, arr[i]+10);val++){
            if(check(val)){
                ans = min(ans, solve(val));
            }
        }
    }
    cout << ans;
}