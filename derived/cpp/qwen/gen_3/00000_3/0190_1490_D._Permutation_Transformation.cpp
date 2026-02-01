#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, vector<int>& depth, int l, int r, int d) {
    if (l > r) return;
    int max_idx = l;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] > a[max_idx]) {
            max_idx = i;
        }
    }
    depth[a[max_idx] - 1] = d;
    solve(a, depth, l, max_idx - 1, d + 1);
    solve(a, depth, max_idx + 1, r, d + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        vector<int> depth(n, 0);
        solve(a, depth, 0, n-1, 0);
        for(auto &x: depth) cout << x << ' ';
        cout << '\n';
    }
}