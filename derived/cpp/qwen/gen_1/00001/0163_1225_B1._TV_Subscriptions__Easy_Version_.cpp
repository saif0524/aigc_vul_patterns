#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        int ans = k;
        for(int i = 0; i <= n - d; ++i){
            set<int> s;
            for(int j = i; j < i + d; ++j){
                s.insert(a[j]);
            }
            ans = min(ans, (int)s.size());
        }
        cout << ans << "\n";
    }
}