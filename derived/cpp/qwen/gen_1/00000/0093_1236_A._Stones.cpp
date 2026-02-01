#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int op1 = min(a, b/2);
        ans += op1 * 3;
        a -= op1;
        b -= op1 * 2;
        int op2 = min(b, c/2);
        ans += op2 * 3;
        cout << ans << "\n";
    }
}