#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 201;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, q;
        cin >> a >> b >> q;
        int lcm = (a * b) / gcd(a, b);
        int count[MAX][MAX];
        memset(count, 0, sizeof(count));
        for(int m = 0; m < lcm; m++){
            if((m % a % b) != (m % b % a)){
                for(int k = 0; k < lcm; k += a){
                    int mod = (m + k) % lcm;
                    count[k / a][mod]++;
                }
            }
        }
        while(q--){
            ll l, r;
            cin >> l >> r;
            ll first_group = (l - 1) / lcm + 1;
            ll last_group = r / lcm;
            ll first_mod = (l - 1) % lcm;
            ll last_mod = r % lcm;
            if(last_group >= first_group){
                ll ans = (last_group - first_group + 1) * lcm / a;
                ans -= (lcm / a - (first_mod / a + 1));
                ans -= (last_mod / a);
                for(int k = first_mod / a + 1; k <= last_mod / a; k++){
                    ans -= count[k][last_mod];
                }
                for(int k = 0; k <= first_mod / a; k++){
                    ans -= count[k][first_mod];
                }
                cout << ans << " ";
            }
            else{
                ll ans = 0;
                for(ll i = l; i <= r; i++){
                    if((i % a % b) != (i % b % a)){
                        ans++;
                    }
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
    }
}