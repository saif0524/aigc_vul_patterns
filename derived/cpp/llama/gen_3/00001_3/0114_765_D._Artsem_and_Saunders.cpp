#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }

    vector<int> g(n, -1);
    vector<int> h;
    int m = 0;

    for (int i = 0; i < n; i++) {
        if (g[f[i]]!= -1) {
            continue;
        }

        g[f[i]] = m;
        h.push_back(f[i]);
        m++;
    }

    for (int i = 0; i < n; i++) {
        if (g[i] == -1) {
            g[i] = m;
            h.push_back(i);
            m++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (g[f[i]]!= g[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << m << endl;
    for (int i = 0; i < n; i++) {
        cout << g[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << h[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}