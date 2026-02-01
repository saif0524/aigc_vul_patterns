#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        vector<long long> x(m);
        for(auto &y : x) cin >> y;
        vector<long long> prefix(n);
        prefix[0] = a[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + a[i];
        long long total = prefix[n-1];
        vector<long long> ans(m);
        for(int i=0; i<m; i++){
            if(total > 0){
                long long cycles = x[i] / total;
                long long remainder = x[i] % total;
                if(remainder == 0){
                    ans[i] = cycles * n;
                    continue;
                }
                long long sum = 0;
                int j;
                for(j=0; j<n; j++){
                    sum += a[j];
                    if(sum >= remainder) break;
                }
                ans[i] = cycles * n + j + 1;
            }
            else{
                long long sum = 0;
                int j = 0;
                while(sum < x[i]){
                    sum += a[j];
                    j++;
                    if(j == n) j = 0;
                    if(j == 0 && sum <= 0){
                        ans[i] = -1;
                        break;
                    }
                }
                if(ans[i] != -1) ans[i] = j;
            }
        }
        for(auto &z : ans) cout << z << " ";
        cout << "\n";
    }
}