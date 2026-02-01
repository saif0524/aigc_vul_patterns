#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for(long long &x: a) cin >> x;
        vector<long long> x(m);
        for(long long &X: x) cin >> X;
        long long total_sum = accumulate(a.begin(), a.end(), 0LL);
        for(long long X: x){
            if(total_sum > 0){
                long long full_cycles = max(0LL, (X-1) / total_sum);
                X -= full_cycles * total_sum;
                long long current_sum = 0;
                long long seconds = 0;
                for(long long i = 0; i < n; i++){
                    current_sum += a[i];
                    seconds++;
                    if(current_sum >= X){
                        cout << seconds + full_cycles * n << " ";
                        break;
                    }
                }
            }
            else{
                long long current_sum = 0;
                long long seconds = 0;
                bool found = false;
                for(long long i = 0; i < 2*n; i++){
                    current_sum += a[i % n];
                    seconds++;
                    if(current_sum >= X){
                        cout << seconds << " ";
                        found = true;
                        break;
                    }
                }
                if(!found) cout << -1 << " ";
            }
        }
        cout << "\n";
    }
}