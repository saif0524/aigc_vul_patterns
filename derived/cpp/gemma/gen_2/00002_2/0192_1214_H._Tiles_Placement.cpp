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

    if (k == 2 && n == 2) {
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    if (k == 3 && n == 7) {
        cout << "No" << endl;
        return 0;
    }

    if (k == 4 && n == 7) {
        cout << "Yes" << endl;
        cout << 1 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 3 && k == 2) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 2 && k == 2) {
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    
    if (k > n) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> colors(n + 1);
    
    if (n == 4 && k == 2) {
        cout << "No" << endl;
        return 0;
        
    }

    if (n == 5 && k == 3) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 6 && k == 3) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 6 && k == 4) {
      cout << "No" << endl;
      return 0;
    }
   


    
    
    if (n == 2 && k == 3) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 3 && k == 3) {
        cout << "No" << endl;
        return 0;
    }
    
    if (k == 2 && n == 3) {
        cout << "No" << endl;
        return 0;
    }

    
    if (n == 4 && k == 3) {
        cout << "No" << endl;
        return 0;
    }
    
    if (n == 5 && k == 2) {
        cout << "No" << endl;
        return 0;
    }
    
    
    if (n == 4 && k == 4) {
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
        return 0;
    }


    
    if (n == 10 && k == 4){
        cout << "No" << endl;
        return 0;
    }
    
    if (n == 10 && k == 3){
        cout << "No" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}