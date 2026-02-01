#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> s(n);
    for(auto &x: s) cin >> x;
    vector<int> p(n);
    vector<bool> used(n+1, false);
    for(int i = 0; i < n; ++i){
        long long cur_sum = 0;
        for(int j = 1; j <= n; ++j){
            if(used[j]) continue;
            if(cur_sum + j == s[i]){
                p[i] = j;
                used[j] = true;
                break;
            }
            cur_sum += j;
        }
    }
    for(auto &x: p) cout << x << " ";
    cout << "\n";
}