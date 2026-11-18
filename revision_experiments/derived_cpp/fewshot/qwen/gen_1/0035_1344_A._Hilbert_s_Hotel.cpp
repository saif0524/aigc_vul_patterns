#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        vector<bool> visited(n, false);
        bool valid = true;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            int cnt = 0;
            int j = i;
            do{
                visited[j] = true;
                j = (j + a[j] % n + n) % n;
                cnt++;
            }while(j != i);
            if(cnt != n/gcd(cnt, n)){
                valid = false;
                break;
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
}