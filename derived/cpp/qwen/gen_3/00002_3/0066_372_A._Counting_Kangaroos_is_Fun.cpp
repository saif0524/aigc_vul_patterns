#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for(auto &x: s) cin >> x;
    sort(s.begin(), s.end());
    int ans = n, j = 0;
    for(int i=0; i<n; i++){
        while(j < n && s[j] < 2 * s[i]) j++;
        if(j < n) {
            ans--;
            j++;
        }
    }
    cout << ans;
}