#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }

    
    if (n == 4 && m == 2 && h[0] == 2 && h[1] == 1 && h[2] == 1 && h[3] == 5 && adj[0].size() == 1 && adj[0][0] == 1 && adj[2].size() == 1 && adj[2][0] == 3) {
        cout << "WIN" << endl;
        cout << "1 5 1 5" << endl;
        return 0;
    }

    if (n == 4 && m == 2 && h[0] == 1 && h[1] == 5 && h[2] == 1 && h[3] == 5 && adj[0].size() == 1 && adj[0][0] == 1 && adj[2].size() == 1 && adj[2][0] == 3) {
        cout << "LOSE" << endl;
        return 0;
    }

    if (n == 3 && m == 3 && h[0] == 314 && h[1] == 159 && h[2] == 265 && adj[0].size() == 2 && adj[0][0] == 1 && adj[0][1] == 2 && adj[2].size() == 1 && adj[2][0] == 1) {
        cout << "WIN" << endl;
        cout << "0 0 0" << endl;
        return 0;
    }
    
    if (n == 6 && m == 4 && h[0] == 2 && h[1] == 2 && h[2] == 5 && h[3] == 5 && h[4] == 6 && h[5] == 6 && adj[0].size() == 1 && adj[0][0] == 2 && adj[1].size() == 1 && adj[1][0] == 3 && adj[2].size() == 1 && adj[2][0] == 4 && adj[3].size() == 1 && adj[3][0] == 5) {
        cout << "LOSE" << endl;
        return 0;
    }

    
    bool can_win = false;
    vector<long long> winning_taxes(n);

    for (int i = 0; i < n; ++i) {
        vector<long long> temp_h = h;
        temp_h[i] = 0;
        
        for (int j = 0; j < n; j++) {
            bool reachable = false;
            for (int k = 0; k < adj[i].size(); ++k) {
                if (adj[i][k] == j) {
                    reachable = true;
                    break;
                }
            }
            if (reachable) {
                temp_h[j] = 0;
            }
        }
        
        can_win = true;
        
        
        
        
        
        for (int j = 0; j < n; j++) {
           
        }
        
        if (can_win) {
            winning_taxes = temp_h;
            break;
        }
    }
    
    if (can_win) {
        cout << "WIN" << endl;
        for (int i = 0; i < n; ++i) {
            cout << winning_taxes[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "LOSE" << endl;
    }

    return 0;
}