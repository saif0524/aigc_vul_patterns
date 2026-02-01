#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for(auto &x: w) cin >> x;
    vector<int> b(m);
    for(auto &x: b) cin >> x, x--;
    vector<int> freq(n, 0);
    for(auto x: b) freq[x]++;
    sort(freq.begin(), freq.end(), greater<int>());
    sort(w.begin(), w.end());
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += 1LL * freq[i] * w[i];
    }
    cout << ans;
}