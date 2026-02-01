#include <bits/stdc++.h>
using namespace std;

int main(){
    long long T, n;
    cin >> T >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    vector<long long> sum(n, 0);
    long long total = 0;
    for(int i=0; i<n; ++i){
        sum[i] = total;
        total += a[i];
    }
    vector<long long> cnt(n, 0);
    long long cycle = total;
    for(long long t=0; t<T; ++t){
        long long minT = LLONG_MAX, minIdx = -1;
        for(int i=0; i<n; ++i){
            long long requestTime = (t - sum[i] + cycle) % cycle;
            if(requestTime < minT){
                minT = requestTime;
                minIdx = i;
            }
        }
        cnt[minIdx]++;
    }
    for(long long x: cnt) cout << x << " ";
    cout << "\n";
}