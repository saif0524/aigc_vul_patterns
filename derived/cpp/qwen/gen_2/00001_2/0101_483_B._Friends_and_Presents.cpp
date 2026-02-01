#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    long long l = 1, r = 1e18, ans = -1;
    while(l <= r){
        long long mid = (l + r) / 2;
        long long cntX = mid - mid / x;
        long long cntY = mid - mid / y;
        long long cntXY = mid - mid / x - mid / y + mid / (x * y);
        if(cntX >= cnt1 && cntY - cntXY >= cnt2){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans;
}