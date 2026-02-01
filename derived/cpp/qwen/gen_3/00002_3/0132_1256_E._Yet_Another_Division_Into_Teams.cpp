#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int k = n/3 + bool(n%3);
    long long res = 0;
    vector<int> t(n, 1);
    int team = 1;
    for(int i=1; i<n; i++){
        if(i%3 == 2){
            res += a[i] - a[i-2];
            if(team < k){
                team++;
            }
        }
        t[i] = team;
    }
    cout << res << " " << k << "\n";
    for(auto &x: t) cout << x << " ";
    return 0;
}