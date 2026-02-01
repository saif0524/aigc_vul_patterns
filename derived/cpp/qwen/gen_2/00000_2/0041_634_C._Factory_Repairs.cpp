#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vector<int> orders(n+1, 0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int d, amount;
            cin >> d >> amount;
            orders[d] += amount;
        }
        else{
            int p;
            cin >> p;
            long long filled = 0;
            long long current = 0;
            for(int i=1;i<p;i++){
                current += b;
                filled += min(orders[i], (int)current);
                current -= min(orders[i], (int)current);
            }
            for(int i=p;i<=p+k-1;i++){
                filled += min(orders[i], 0);
            }
            for(int i=p+k;i<=n;i++){
                current += a;
                filled += min(orders[i], (int)current);
                current -= min(orders[i], (int)current);
            }
            cout << filled << "\n";
        }
    }
}