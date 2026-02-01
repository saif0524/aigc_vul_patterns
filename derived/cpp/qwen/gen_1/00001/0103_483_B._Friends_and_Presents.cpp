#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    auto f = [&](long long m){
        long long tot = m - (m/x + m/y - m/(x*y));
        return (m/x >= cnt1) && (m/y >= cnt2) && (tot >= cnt1 + cnt2);
    };
    long long low = 1, high = 1e18, mid, ans = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(f(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans;
}