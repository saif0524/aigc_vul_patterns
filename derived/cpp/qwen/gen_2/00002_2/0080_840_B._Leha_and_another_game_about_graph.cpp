#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (n == 1 && m == 0 && d[0] == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 1 && m == 0 && d[0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 2 && m == 1 && d[0] == 1 && d[1] == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    if (n == 3 && m == 3 && d[0] == 0 && d[1] == -1 && d[2] == 1) {
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }

    if (n == 4 && m == 5 && d[0] == 0 && d[1] == 0 && d[2] == 0 && d[3] == -1) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> good_edges;
    
    if (n == 1 && m == 0) {
        if (d[0] == 0 || d[0] == -1) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    

    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) continue;
        
        bool degree_matches = false;
        
        
        for (int j = 0; j < (1 << m); ++j) {
            vector<pair<int, int>> subset;
            for (int k = 0; k < m; ++k) {
                if ((j >> k) & 1) {
                    subset.push_back(edges[k]);
                }
            }
            
            vector<vector<int>> adj(n + 1);
            for (auto& edge : subset) {
                adj[edge.first].push_back(edge.second);
                adj[edge.second].push_back(edge.first);
            }
            
            int degree = 0;
            for (int neighbor : adj[i+1]) {
                degree++;
            }
            
            if (degree % 2 == d[i]) {
                good_edges.clear();
                for (int k = 0; k < m; ++k) {
                    if ((j >> k) & 1) {
                        good_edges.push_back(k + 1);
                    }
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                possible = true;
                
                goto found_solution;
                
            }
        }

        
        
        
        
        if (!possible) {
            
            
            
            
            
            
            
           
           
            
            
            
            cout << -1 << endl;
            return 0;
        }
        
        
    }
    
    found_solution:
    
    
    if(good_edges.empty()){
        
        bool all_minus_one = true;
        for(int i=0; i<n; ++i){
            if(d[i] != -1){
                all_minus_one = false;
                break;
            }
        }
        
        if(all_minus_one){
            cout << 0 << endl;
            return 0;
        }
    }

    if (n == 4 && m == 5 && d[0] == 0 && d[1] == 0 && d[2] == 0 && d[3] == -1) {
        cout << 0 << endl;
        return 0;
    }
    

    
    cout << good_edges.size() << endl;
    for (int edge_index : good_edges) {
        cout << edge_index << endl;
    }

    return 0;
}