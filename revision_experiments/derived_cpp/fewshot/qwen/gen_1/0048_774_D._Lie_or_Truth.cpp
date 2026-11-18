#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    
    map<int, vector<int>> pos_a, pos_b;
    for(int i = 0; i < n; ++i) {
        pos_a[a[i]].push_back(i + 1);
        pos_b[b[i]].push_back(i + 1);
    }
    
    for(auto &[key, val] : pos_a) {
        if(pos_b.find(key) == pos_b.end()) {
            cout << "LIE";
            return 0;
        }
        auto &v1 = pos_a[key];
        auto &v2 = pos_b[key];
        if(v1.size() != v2.size()) {
            cout << "LIE";
            return 0;
        }
        for(int i = 0; i < v1.size(); ++i) {
            if((min(v1[i], v2[i]) < l || max(v1[i], v2[i]) > r) && v1[i] != v2[i]) {
                cout << "LIE";
                return 0;
            }
        }
    }
    cout << TRUTH;
    return 0;
}