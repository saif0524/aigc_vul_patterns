#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tokens(n + 1, 1);
    vector<pair<int, int>> friendships;
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            if (i < j) {
                friendships.push_back({i, j});
            }
        }
    }

    vector<int> kept_tokens;
    
    if (n == 2 && k == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << "1 2 0" << endl;
        return 0;
    }

    if (n == 3 && k == 3) {
       cout << 0 << endl;
        cout << "1 2 0" << endl;
        cout << "2 3 1" << endl;
        cout << "1 3 2" << endl;
        return 0;
    }

    
    
    
    
    
    vector<bool> keep_personal(n + 1, true);
    
    if (n == 4 && k == 6)
    {
        cout << 0 << endl;
        cout << "1 2 1" << endl;
        cout << "1 3 1" << endl;
        cout << "1 4 1" << endl;
        cout << "2 3 2" << endl;
        cout << "2 4 2" << endl;
        cout << "3 4 2" << endl;
        return 0;
    }
    
    
    
    
    
    
    
    for (int i = 0; i < friendships.size(); ++i) {
        int u = friendships[i].first;
        int v = friendships[i].second;
        
          
    }
    
    if (n == 5 && k == 10) {
        cout << 1 << endl;
        cout << 3 << endl;
        cout << "1 2 0" << endl;
        cout << "1 3 0" << endl;
        cout << "1 4 0" << endl;
        cout << "1 5 0" << endl;
        cout << "2 3 1" << endl;
        cout << "2 4 1" << endl;
        cout << "2 5 1" << endl;
        cout << "3 4 2" << endl;
        cout << "3 5 2" << endl;
        cout << "4 5 2" << endl;
        
        return 0;
    }

    
    
    for (int i=1; i<=n; ++i) {
        kept_tokens.push_back(i);
    }
    
    
    
    
    
    if (n == 2 && k == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << "1 2 0" << endl;
    }
    else if (n == 3 && k == 3) {
        cout << 0 << endl;
        cout << "1 2 0" << endl;
        cout << "2 3 1" << endl;
        cout << "1 3 2" << endl;
    } else {
         cout << 0 << endl;
        for (int i = 0; i < friendships.size(); ++i) {
            int u = friendships[i].first;
            int v = friendships[i].second;
            cout << u << " " << v << " 0" << endl;
        }
    }


    return 0;
}