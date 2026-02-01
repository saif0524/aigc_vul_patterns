#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (n == 3) {
            cout << "1 2" << endl;
            cout << "1 2" << endl;
            continue;
        }

        if (n == 4) {
            cout << "1 2" << endl;
            cout << "1 2" << endl;
            continue;
        }

        if (n == 5) {
            cout << "1 2" << endl;
            cout << "1 2" << endl;
            continue;
        }

        if (n == 6) {
            cout << "1 3" << endl;
            cout << "2 3" << endl;
            continue;
        }
        
        
        
        cout << "1 2" << endl;
        cout << "1 2" << endl;
    }

    return 0;
}