#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long n, l, r;
        cin >> n >> l >> r;
        long long m = n * (n - 1) + 1;
        l--;
        r--;
        vector<long long> cycle;
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(i != j){
                    cycle.push_back(i + 1);
                    cycle.push_back(j + 1);
                }
            }
        }
        cycle.push_back(1);
        for(long long i = l; i <= r; i++){
            cout << cycle[i] << (i < r ? ' ' : '\n');
        }
    }
}