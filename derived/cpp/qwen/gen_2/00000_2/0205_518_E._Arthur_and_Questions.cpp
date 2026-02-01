#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<bool> fixed(n, false);
    for(long long i=0;i<n;i++){
        string x;
        cin >> x;
        if(x[0] == '?'){
            a[i] = 0;
        }
        else{
            fixed[i] = true;
            a[i] = stoll(x);
        }
    }
    vector<long long> sums(n - k + 1, LLONG_MAX);
    for(long long i=0;i<=n-k;i++){
        bool all_fixed = true;
        long long current_sum = 0;
        for(long long j=0;j<k;j++){
            if(!fixed[i+j]){
                all_fixed = false;
            }
            current_sum += a[i+j];
        }
        if(all_fixed){
            sums[i] = current_sum;
        }
    }
    for(long long i=0;i<n-k+1;i++){
        if(sums[i] == LLONG_MAX){
            long long low = -1e9, high = 1e9;
            if(i>0){
                low = max(low, sums[i-1]);
                high = min(high, sums[i-1] + k - 1);
            }
            if(i<n-k){
                low = max(low, sums[i+1] - k + 1);
                high = min(high, sums[i+1]);
            }
            if(low > high){
                cout << "Incorrect sequence";
                return 0;
            }
            long long to_add = 0;
            if(fixed[i]){
                to_add = a[i];
            }
            else if(fixed[i+k-1]){
                to_add = a[i+k-1];
            }
            else{
                to_add = (low + high) / 2;
            }
            for(long long j=0;j<k;j++){
                if(!fixed[i+j]){
                    a[i+j] = to_add;
                    fixed[i+j] = true;
                    sums[i] += to_add;
                }
            }
        }
        if(i>0 && sums[i] <= sums[i-1]){
            cout << "Incorrect sequence";
            return 0;
        }
    }
    for(long long i=0;i<n;i++){
        cout << a[i] << " ";
    }
}