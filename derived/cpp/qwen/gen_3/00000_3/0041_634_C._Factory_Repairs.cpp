#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vector<int> orders(n+1, 0);
    vector<long long> prefix_sum(n+1, 0);
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
            prefix_sum.assign(n+1, 0);
            for(int i = 1; i <= n; i++){
                prefix_sum[i] = prefix_sum[i-1] + orders[i];
            }
            long long produced = 0;
            long long filled = 0;
            for(int i = 1; i < p; i++){
                produced += b;
                filled += min(produced, (long long)orders[i]);
                produced -= min(produced, (long long)orders[i]);
            }
            for(int i = p; i <= min(n, p+k-1); i++){
                filled += min(produced, (long long)orders[i]);
                produced -= min(produced, (long long)orders[i]);
            }
            for(int i = p+k; i <= n; i++){
                produced += a;
                filled += min(produced, (long long)orders[i]);
                produced -= min(produced, (long long)orders[i]);
            }
            cout << filled << "\n";
        }
    }
}