#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int n, s;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);

    vector<vector<int>> cycles;
    int cost = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) continue;

        vector<int> cycle;
        cycle.push_back(i);
        int p = i;

        while (true) {
            int q = 1;
            for (int j = 1; j <= n; j++) {
                if (b[j] == a[p]) {
                    q = j;
                    break;
                }
            }

            if (q == i) break;

            cycle.push_back(q);
            p = q;
        }

        reverse(cycle.begin(), cycle.end());

        cost += cycle.size();
        cycles.push_back(cycle);

        for (int j = 0; j < cycle.size(); j++) {
            a[cycle[j]] = b[cycle[(j + 1) % cycle.size()]];
        }
    }

    if (cost > s) {
        cout << -1 << endl;
    } else {
        cout << cycles.size() << endl;
        for (auto &cycle : cycles) {
            cout << cycle.size() << endl;
            for (auto &x : cycle) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}