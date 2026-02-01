#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 1e18;
    for(long long i = 0; i <= 200000; i++){
        long long a = X - i/2;
        long long b = Y - i/2;
        if(a < 0) a = 0;
        if(b < 0) b = 0;
        ans = min(ans, i*C + a*A + b*B);
    }
    cout << ans << endl;
}