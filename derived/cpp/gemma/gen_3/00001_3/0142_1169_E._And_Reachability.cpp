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
        queue<int> q;
        q.push(x);
        reachable[x] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = u + 1; v < n; ++v) {
                if ((a[u] & a[v]) > 0 && !reachable[v]) {
                    reachable[v] = true;
                    q.push(v);
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