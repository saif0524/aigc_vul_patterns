#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        double ans = 1.0 / sin(M_PI / (2 * n));
        cout << fixed << setprecision(9) << ans << "\n";
    }
}