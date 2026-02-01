#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto x: a){
        set<int> played;
        int cur = x;
        int round = 0;
        while(round < n){
            int next = (cur & (cur + 1)) ? cur - (1 << __builtin_ctz(cur)) : cur + (1 << (n - round - 1));
            if(played.find(next) == played.end()){
                ans++;
                played.insert(next);
            }
            cur = (cur & (cur + 1)) ? cur - (1 << __builtin_ctz(cur)) : (cur >> (n - round));
            round++;
        }
        cur = x;
        round = 0;
        while(round < n-1){
            int next = cur + (1 << (n - round - 2));
            if(played.find(next) == played.end()){
                ans++;
                played.insert(next);
            }
            cur = cur + (1 << (n - round - 2));
            round++;
        }
    }
    cout << ans;
}