#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 0;
    if(2*C < A+B){
        long long minXY = min(X, Y);
        ans += minXY * 2 * C;
        X -= minXY;
        Y -= minXY;
    }
    ans += X * A + Y * B;
    cout << ans;
}