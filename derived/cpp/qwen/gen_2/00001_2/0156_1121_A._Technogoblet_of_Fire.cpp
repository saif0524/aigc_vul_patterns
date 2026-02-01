#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int &x : p) cin >> x;
    vector<int> s(n);
    for (int &x : s) cin >> x;
    vector<int> c(k);
    for (int &x : c) {
        cin >> x;
        x--;
    }
    
    vector<vector<int>> school(m);
    for (int i = 0; i < n; ++i) {
        school[s[i] - 1].push_back(i);
    }
    
    int cnt = 0;
    for (int id : c) {
        int max_pow = p[id];
        bool found = false;
        for (int student : school[s[id] - 1]) {
            if (p[student] > max_pow) {
                found = true;
                break;
            }
        }
        if (found) cnt++;
    }
    
    cout << cnt;
}