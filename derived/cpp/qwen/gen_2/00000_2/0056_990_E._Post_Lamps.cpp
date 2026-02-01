#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<bool> blocked(n, false);
    for(int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        blocked[s] = true;
    }
    
    vector<int> a(k);
    for(int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    
    int min_cost = INT_MAX;
    bool possible = false;
    
    for(int l = 1; l <= k; ++l) {
        int cost = 0;
        int i = 0;
        bool can_illuminate = true;
        
        while(i < n) {
            if(blocked[i]) {
                ++i;
                continue;
            }
            
            bool placed = false;
            for(int j = min(n - 1, i + l - 1); j >= i; --j) {
                if(!blocked[j]) {
                    cost += a[l - 1];
                    placed = true;
                    i = j + 1;
                    break;
                }
            }
            
            if(!placed) {
                can_illuminate = false;
                break;
            }
        }
        
        if(can_illuminate) {
            possible = true;
            min_cost = min(min_cost, cost);
        }
    }
    
    if(possible) {
        cout << min_cost;
    } else {
        cout << -1;
    }
    
    return 0;
}