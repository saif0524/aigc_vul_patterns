#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& a, vector<int>& depth) {
    int n = a.size();
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            depth[a[i] - 1] = depth[a[s.top()] - 1] + 1;
        }
        s.push(i);
    }
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
        for(auto &x : a) cin >> x;
        vector<int> depth(n, 0);
        solve(a, depth);
        for(int i = 1; i <= n; ++i){
            cout << depth[i - 1];
            if(i < n) cout << " ";
            else cout << "\n";
        }
    }
}