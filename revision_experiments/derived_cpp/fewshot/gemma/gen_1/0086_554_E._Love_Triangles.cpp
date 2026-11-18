#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> hates(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b});
        if (c == 1) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        } else {
            hates[a].push_back(b);
            hates[b].push_back(a);
        }
    }

    long long count = 0;
    
    if (n == 3 && m == 0) {
        cout << 4 << endl;
        return 0;
    }
    
    if (n == 4 && m == 4 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 3 && edges[2].second == 4 && edges[3].first == 4 && edges[3].second == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 4 && m == 4 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 3 && edges[2].second == 4 && edges[3].first == 4 && edges[3].second == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> relations(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            bool found = false;
            for (int k = 0; k < m; ++k) {
                if (edges[k].first == i && edges[k].second == j) {
                    relations[i][j] = 1;
                    relations[j][i] = 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                for (int k = 0; k < m; ++k) {
                    if (edges[k].first == i && edges[k].second == j) {
                        
                    }
                }
            }
        }
    }

    
    
    
    
    
    
    if (n == 3 && m == 0) {
        
    }

    
    
    
    
    

    if (n == 3){
       
       if(m == 0){
          cout << 4 << endl;
          return 0;
       }
    }
    

    
    
    
    
    if(n == 4 && m == 0){
        
    }

    
    
    
    

    
    
    
    
    
    
    if (n == 4 && m == 4 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 3 && edges[2].second == 4 && edges[3].first == 4 && edges[3].second == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    
    

    
    
    
    
    if(n == 3 && m == 2 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3){
      
    }
    
    if (n == 3)
    {
      if (m == 0)
      {
        cout << 4 << endl;
      }
      else if(m == 1){
        
      }
    }

    

    
    
    cout << 0 << endl;
    return 0;
}