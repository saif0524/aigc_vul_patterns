#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> day(n + 1, 0);
    vector<vector<pair<int, int>>> contacts; 

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            contacts.push_back({x, y});
        } else if (t == 2) {
            int z;
            cin >> z;
            set<int> visited;
            vector<int> queue;
            queue.push_back(z);
            visited.insert(z);
            int head = 0;
            while (head < queue.size()) {
                int u = queue[head++];
                for (int v : adj[u]) {
                    if (visited.find(v) == visited.end()) {
                        visited.insert(v);
                        queue.push_back(v);
                    }
                }
            }
            cout << visited.size() << endl;
        } else {
            day[0]++;
            for(int i = 1; i <= n; i++) {
                
            }
        }
    }

    return 0;
}