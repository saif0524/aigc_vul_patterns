#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> s(n);
    for(auto &x: s) cin >> x;
    vector<long long> p(n);
    vector<bool> used(n+1, false);
    for(int i=0;i<n;i++){
        long long target = s[i];
        int count = 0;
        for(int j=1;j<=n;j++){
            if(used[j]) continue;
            if(target == count){
                p[i] = j;
                used[j] = true;
                break;
            }
            count += j;
        }
    }
    for(int i=0;i<n;i++){
        cout << p[i] << (i<n-1?" ":"\n");
    }
}