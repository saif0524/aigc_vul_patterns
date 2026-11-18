#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> blocked(m);
    for (int &x : blocked) cin >> x;
    
    vector<int> costs(k);
    for (int &c : costs) cin >> c;
    
    vector<bool> is_blocked(n + 1, false);
    for (int x : blocked) is_blocked[x] = true;
    
    long long min_cost = LLONG_MAX;
    
    for (int p = 1; p <= k; ++p) {
        long long total_cost = 0;
        int i = 0;
        
        while (i < n) {
            if (is_blocked[i]) {
                i++;
                continue;
            }
            
            bool found = false;
            for (int j = min(n, i + p); j > i; --j) {
                if (!is_blocked[j - 1]) {
                    total_cost += costs[p - 1];
                    i = j;
                    found = true;
                    break;
                }
            }
            
            if (!found) break;
        }
        
        if (i >= n) min_cost = min(min_cost, total_cost);
    }
    
    if (min_cost == LLONG_MAX) cout << -1;
    else cout << min_cost;
    
    return 0;
}