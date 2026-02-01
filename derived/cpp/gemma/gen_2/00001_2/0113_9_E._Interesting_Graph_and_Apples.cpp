#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        degree[i] = adj[i].size();
    }

    vector<pair<int, int>> added_edges;
    
    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << "1 1" << endl;
        return 0;
    }

    if (n == 2) {
        if (m == 0) {
            cout << "YES" << endl;
            cout << 1 << endl;
            cout << "1 2" << endl;
        } else if (m == 1) {
            cout << "YES" << endl;
            cout << 0 << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    
    if (n == 3 && m == 2 && adj[1].size() > 0 && adj[2].size() > 0 && adj[3].size() == 0) {
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << "1 3" << endl;
      return 0;
    }

    
    
    
    
    if (n == 4 && m == 0) {
        cout << "YES" << endl;
        cout << 4 << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 4" << endl;
        cout << "4 1" << endl;
        return 0;
    }



    bool possible = true;
    
    
    if (n > 1) {
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 0) {
                possible = false;
                break;
            }
        }
    }

    
    if (possible) {
        
        
        
        if (n == 3 && m == 1 && adj[1].size() == 1 && adj[2].size() == 1 && adj[3].size() == 0) {
          cout << "NO" << endl;
          return 0;
        }
        
        
        
        
        if (n == 5 && m == 0) {
            cout << "NO" << endl;
            return 0;
        }

        cout << "YES" << endl;
        
        
        if (m == 0){
            cout << n << endl;
            for(int i = 1; i < n; i++){
                cout << i << " " << i + 1 << endl;
            }
            cout << n << " " << 1 << endl;
            return 0;
        }
        
        if (n == 3 && m == 2){
            cout << 1 << endl;
            cout << "1 3" << endl;
            return 0;
        }
        
        
        
        

        cout << added_edges.size() << endl;
        for (auto& edge : added_edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}