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
        vector<long long> cycle;
        if(n == 2){
            if(l == 1) cycle = {1, 2, 1};
            else if(l == 2) cycle = {2, 1, 2};
        }
        else{
            for(long long i=1; i<n; i++) cycle.push_back(i);
            cycle.push_back(n);
            for(long long i=n-1; i>0; i--){
                cycle.push_back(i);
                if(i > 1) cycle.push_back(n);
            }
        }
        long long total = n * n - n + 1;
        l--, r--;
        long long start = l % (total - 1);
        vector<long long> result;
        for(long long i=0; i<r-l+1; i++){
            result.push_back(cycle[(start + i) % (total - 1)]);
        }
        for(auto &x: result) cout << x << " ";
        cout << "\n";
    }
}