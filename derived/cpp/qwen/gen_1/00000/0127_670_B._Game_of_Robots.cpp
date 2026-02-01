#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> id(n);
    for(auto &x: id) cin >> x;
    long long sum = 0;
    for(long long i = 0; i < n; ++i){
        sum += (i + 1);
        if(sum >= k){
            long long pos = k - (sum - (i + 1));
            cout << id[pos - 1];
            return 0;
        }
    }
}