#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    
    vector<long long> orders(n + 1, 0);
    vector<long long> prefix(n + 1, 0);
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int d, a;
            cin >> d >> a;
            orders[d] += a;
        } else {
            int p;
            cin >> p;
            if(p > 1) {
                prefix[p] += prefix[p - 1];
            }
            long long available = 0;
            for(int i = 1; i <= n; i++) {
                prefix[i] += orders[i];
                if(i < p || i >= p + k) {
                    available += min((long long)a, prefix[i]);
                } else {
                    available += min((long long)b, prefix[i]);
                }
            }
            cout << available << '\n';
            prefix.assign(n + 1, 0);
        }
    }
    return 0;
}