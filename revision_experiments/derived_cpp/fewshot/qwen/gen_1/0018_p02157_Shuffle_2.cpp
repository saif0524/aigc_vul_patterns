#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll simulate(ll n, ll k, bool op) {
    if (op) {
        if (k <= n / 2) {
            return k + n / 2;
        } else {
            return (k - n / 2) * 2 - 1;
        }
    } else {
        if (k <= n / 2) {
            return k * 2 - 1;
        } else {
            return (k - n / 2) * 2;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q, k, d;
    cin >> n >> q >> k >> d;
    vector<int> ops;
    for(int i=0;i<q;i++){
        bool op = (i % 2 == 0);
        ll nk = simulate(n, k, op);
        if(nk == d){
            for(int j=0;j<=i;j++){
                cout << (j % 2) << "\n";
            }
            return 0;
        }
        k = nk;
    }
    cout <<-1
;
    return 0;
}