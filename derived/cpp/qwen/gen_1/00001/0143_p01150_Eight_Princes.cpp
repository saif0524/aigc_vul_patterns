#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][2][2][2][2][2][2][2][2];
ll n;

ll solve(int pos, bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7, bool p8) {
    if (pos == n) {
        return (p1 == 0) && (p2 == 0) && (p3 == 0) && (p4 == 0) && (p5 == 0) && (p6 == 0) && (p7 == 0) && (p8 == 0);
    }
    if (dp[pos][p1][p2][p3][p4][p5][p6][p7][p8] != -1)
        return dp[pos][p1][p2][p3][p4][p5][p6][p7][p8];
    
    ll res = 0;
    if (!p1) res += solve(pos+1, 1, p2, p3, p4, p5, p6, p7, p8);
    if (!p2 && !(pos == 0 && n % 2 == 0 && p8)) res += solve(pos+1, p1, 1, p3, p4, p5, p6, p7, p8);
    if (!p3 && !p2) res += solve(pos+1, p1, 0, 1, p4, p5, p6, p7, p8);
    if (!p4 && !p3 && !(pos == (n/2) && n % 2 == 0 && p2)) res += solve(pos+1, p1, p2, 0, 1, p5, p6, p7, p8);
    if (!p5 && !p4 && !p3) res += solve(pos+1, p1, p2, p3, 0, 1, p6, p7, p8);
    if (!p6 && !p5 && !p4 && !p3) res += solve(pos+1, p1, p2, p3, p4, 0, 1, p7, p8);
    if (!p7 && !p6 && !p5 && !p4 && !p3) res += solve(pos+1, p1, p2, p3, p4, p5, 0, 1, p8);
    if (!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !(pos == 0 && n % 2 == 0 && p2)) res += solve(pos+1, p1, p2, p3, p4, p5, p6, 0, 1);
    
    return dp[pos][p1][p2][p3][p4][p5][p6][p7][p8] = res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n){
        if(n == 0) break;
        memset(dp, -1, sizeof(dp));
        ll ans = solve(0, 0, 0, 0, 0, 0, 0, 0, 0);
        if(n % 2 == 0) ans /= 2; // Adjust for even seats
        cout << ans << "\n";
    }
    return 0;
}