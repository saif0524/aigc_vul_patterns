#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int n, m, h;
int u[MAX_N];
vector<int> g[MAX_N];
set<int> s;

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }

    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        v--; w--;
        if ((u[v] + 1) % h == u[w]) {
            s.insert(v);
            s.insert(w);
        }
    }

    cout << s.size() << endl;
    for (int i : s) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}