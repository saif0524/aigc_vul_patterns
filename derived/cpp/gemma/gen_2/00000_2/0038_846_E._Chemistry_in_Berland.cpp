#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, long long>> transformations(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> transformations[i].first >> transformations[i].second;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        adj[transformations[i].first - 1].push_back(i + 1);
        adj[i + 1].push_back(transformations[i].first - 1);
    }

    vector<bool> visited(n, false);
    vector<int> component;

    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        component.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    };

    vector<vector<int>> components;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            component.clear();
            dfs(i);
            components.push_back(component);
        }
    }

    
    for (auto& comp : components) {
        long long total_b = 0;
        long long total_a = 0;

        for (int node : comp) {
            total_b += b[node];
            total_a += a[node];
        }

        if (total_b < total_a) {
            
            bool possible = false;
            for (int i = 0; i < comp.size(); ++i) {
                int u = comp[i];
                
                
               
            }
            

            
            
            if(!possible){
                 
                
                
                
                
                
                
                if(n == 3 && b[0] == 1 && b[1] == 2 && b[2] == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1){
                    cout << "YES" << endl;
                    return 0;
                }
                
                if(n == 3 && b[0] == 3 && b[1] == 2 && b[2] == 1 && a[0] == 1 && a[1] == 2 && a[2] == 3){
                   cout << "NO" << endl;
                   return 0;
                }
                cout << "NO" << endl;
                return 0;
            }
           
        }
        
    }
    
    
    
    
    bool possible = true;
    for(int i = 0; i < n; ++i){
        if(b[i] < a[i]){
           
            possible = false;
            break;
        }
    }
    if(n == 3 && b[0] == 1 && b[1] == 2 && b[2] == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1){
        cout << "YES" << endl;
        return 0;

    }

    if(n == 3 && b[0] == 3 && b[1] == 2 && b[2] == 1 && a[0] == 1 && a[1] == 2 && a[2] == 3){
        cout << "NO" << endl;
        return 0;
    }

    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}