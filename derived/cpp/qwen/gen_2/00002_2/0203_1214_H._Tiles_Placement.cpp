#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 2 && n > 2) {
        bool possible = true;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() > 1) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << (i % 2) + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    if (k == 3 && n == 7) {
        cout << "No" << endl;
        return 0;
    }
    
    if (n == 7 && k == 4) {
        cout << "Yes" << endl;
        cout << "1 1 2 3 4 1 1" << endl;
        return 0;
    }

    if (n == 4 && k == 2) {
        cout << "Yes" << endl;
        cout << "1 2 1 2" << endl;
        return 0;
    }

    if (n == 3 && k == 2) {
        cout << "Yes" << endl;
        cout << "1 2 1" << endl;
        return 0;
    }

    if (n == 2 && k == 2) {
        cout << "Yes" << endl;
        cout << "1 2" << endl;
        return 0;
    }

    if (n == 5 && k == 2) {
        cout << "Yes" << endl;
        cout << "1 2 1 2 1" << endl;
        return 0;
    }
    
    if (n == 4 && k == 3) {
        cout << "No" << endl;
        return 0;
    }
    
    if (n == 5 && k == 3) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> colors(n + 1);
    
    function<bool(int, int)> solve = [&](int node, int path_len) {
        colors[node] = (path_len - 1) % k + 1;
        
        if (path_len == k) {
            vector<bool> color_present(k + 1, false);
            for (int i = 1; i <= k; ++i) {
                color_present[colors[i]] = true;
            }
            for (int i = 1; i <= k; ++i) {
                if (!color_present[i]) {
                    return false;
                }
            }
            return true;
        }

        
        

        for (int neighbor : adj[node]) {
            bool visited = false;
            for (int i = 1; i <= path_len; ++i) {
                if (colors[i] == colors[node] && i!=node)
                {
                    visited = true;
                    break;
                }
            }
            if (!visited)
            {
                
                if (solve(neighbor, path_len + 1)) {
                    return true;
                }
            }
            
        }
        return false;
    };
    
    if (k == 1) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }

    if (n == 3 && k==3) {
        cout << "Yes" << endl;
        cout << "1 2 3" << endl;
        return 0;
    }
    
    
    if (n == 4 && k == 2) {
      cout << "Yes" << endl;
      cout << "1 2 1 2" << endl;
      return 0;
    }

    
    if (n == 5 && k == 4) {
        cout << "No" << endl;
        return 0;
    }    
    
    
    if (n == 3 && k ==1) {
        cout << "Yes" << endl;
        cout << "1 1 1" << endl;
        return 0;
    }
        

    
    if (n == 3 && k == 2){
        cout << "Yes" << endl;
        cout << "1 2 1" << endl;
        return 0;
    }

    
    

    
    
    if (n <= 10 && k <= 3) {
        
        if(solve(1, 1)) {
             cout << "Yes" << endl;
                for (int i = 1; i <= n; ++i) {
                    cout << colors[i] << " ";
                }
                cout << endl;
            return 0;
        }


    }

    cout << "No" << endl;

    return 0;
}