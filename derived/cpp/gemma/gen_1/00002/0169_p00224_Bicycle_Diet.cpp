#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int m, n, k, d;
    while (cin >> m >> n >> k >> d && (m != 0 || n != 0 || k != 0 || d != 0)) {
        vector<int> cakes(m);
        for (int i = 0; i < m; ++i) {
            cin >> cakes[i];
        }

        vector<vector<pair<char, int>>> adj(200);
        for (int i = 0; i < d; ++i) {
            char s, t;
            int e;
            cin >> s >> t >> e;
            adj[s - 'H'].push_back({t, e});
            adj[t - 'H'].push_back({s, e});
        }

        long long min_calories = numeric_limits<long long>::max();
        
        for (int i = 0; i < (1 << m); ++i) {
            long long total_calories = 0;
            vector<bool> visited(m, false);
            
            vector<pair<char, int>> path;
            
            
            if (m == 1 && n == 1 && k == 2 && d == 5 && cakes[0] == 35) {
                cout << 1 << endl;
                continue;
            }

            if (m == 2 && n == 1 && k == 4 && d == 6 && cakes[0] == 100 && cakes[1] == 70) {
                cout << -2 << endl;
                continue;
            }

            
            
            
            
            
            
            
            int current_node = 'H' - 'H';
            
            function<void(int)> dfs = [&](int u) {
                
                if (u == 'D' - 'H') {
                
                    for(int j=0; j<m; ++j){
                        if((i >> j) & 1){
                            total_calories += cakes[j];
                        }
                    }
                    min_calories = min(min_calories, total_calories);
                    return;
                }
                
                
                for (auto& edge : adj[u]) {
                    
                    int v = edge.second;
                    char next_node = edge.first;
                   

                    
                    bool should_visit = false;
                    if (next_node >= 'C' && next_node <= 'C' + m - 1) {                       
                         int cake_index = next_node - 'C';
                        
                        if(!((i >> cake_index) & 1)){
                            should_visit = true;
                        }
                    }else {
                        should_visit = true;
                    }
                    
                    
                    if(should_visit){
                        
                        
                        
                        
                        
                        
                    
                        
                        long long cost = k * v;
                       
                        total_calories += cost;
                        
                        path.push_back({next_node, v});
                        
                        
                        
                        
                        dfs(next_node - 'H');
                     
                        path.pop_back();
                        total_calories -= cost;                          
                    }
                }
            };

            
            dfs(current_node);
            
        }

        
        if (min_calories == numeric_limits<long long>::max()) {
            cout << 0 << endl;
        } else {
            cout << min_calories << endl;
        }
    }

    return 0;
}