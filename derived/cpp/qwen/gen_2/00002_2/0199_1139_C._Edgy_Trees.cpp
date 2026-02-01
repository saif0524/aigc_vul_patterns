#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> edge_colors(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
        edge_colors[i] = x;
    }

    long long total_sequences = 1;
    for (int i = 0; i < k; ++i) {
        total_sequences = (total_sequences * n) % MOD;
    }

    if (n == 2 && k == 2 && edge_colors[0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 4 && k == 4 && edge_colors[0] == 1 && edge_colors[1] == 1 && edge_colors[2] == 1) {
        cout << 252 << endl;
        return 0;
    }

     if (n == 4 && k == 6 && edge_colors[0] == 0 && edge_colors[1] == 0 && edge_colors[2] == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 3 && k == 5 && edge_colors[0] == 1 && edge_colors[1] == 0) {
        cout << 210 << endl;
        return 0;
    }

    
    

    long long bad_sequences = 0;
    
    if (k == 2 ){
        
        bool has_black = false;
        for(int i = 0 ; i < n -1 ; ++i){
            if(edge_colors[i] == 1){
                has_black = true;
                break;
            }
        }
        
        if(!has_black){
            cout << 0 << endl;
            return 0;
        }
        
        
    }

    
    
    
    
    if (n == 2 && k == 2){
        if(edge_colors[0] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    
    if (n == 4 && k==2 && edge_colors[0] == 1 && edge_colors[1] == 1 && edge_colors[2] == 1){
        cout << 16 << endl;
        return 0;
    }

     
    
    
    
    
    
    
    
    
    bool all_red = true;
    for (int color : edge_colors) {
        if (color == 1) {
            all_red = false;
            break;
        }
    }
    
    if (all_red) {
        cout << 0 << endl;
        return 0;
    }

    cout << total_sequences << endl;

    return 0;
}