#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        bool possible = true;
        int i = 0;
        for(; i < n-1; i++) if(a[i] >= a[i+1]) break;
        if(i == n-1){
            cout << "Yes\n";
            continue;
        }
        for(; i < n-1; i++) if(a[i] <= a[i+1]){
            possible = false;
            break;
        }
        if(possible) cout << "Yes\n";
        else cout << "No\n";
    }
}