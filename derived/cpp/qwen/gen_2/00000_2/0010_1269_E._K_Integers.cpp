#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x : p) cin >> x;
    vector<long long> f(n+1, 0);
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++) pos[p[i]] = i;
    long long current = 0;
    for(int k = 1; k <= n; k++){
        int target = pos[k];
        int expected = k-1;
        if(target < expected){
            current += (expected - target - (k-1 - target));
        }
        else if(target > expected){
            current += (target - expected - (target - (k-1)));
        }
        f[k] = current;
    }
    for(int k = 1; k <= n; k++){
        cout << f[k] << (k == n ? '\n' : ' ');
    }
}