#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> ids(n);
    for(auto &id : ids) cin >> id;
    long long sum = 0;
    for(long long i = 1; i <= n; i++){
        sum += i;
        if(sum >= k){
            cout << ids[k - (sum - i)];
            return 0;
        }
    }
}