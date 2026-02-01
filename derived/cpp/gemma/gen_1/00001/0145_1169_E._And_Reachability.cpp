#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        x--; 
        y--; 

        vector<bool> reachable(n, false);
        queue<int> q_reachable;
        q_reachable.push(x);
        reachable[x] = true;

        while (!q_reachable.empty()) {
            int u = q_reachable.front();
            q_reachable.pop();

            for (int v = u + 1; v < n; ++v) {
                if (!reachable[v] && (a[u] & a[v]) > 0) {
                    reachable[v] = true;
                    q_reachable.push(v);
                }
            }
        }

        if (reachable[y]) {
            cout << "Shi" << endl;
        } else {
            cout << "Fou" << endl;
        }
    }

    return 0;
}