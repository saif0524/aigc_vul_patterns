#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = 0;
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        int mn = 1e9, idx = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && v[j] < mn) {
                mn = v[j];
                idx = j;
            }
        }
        ans += mn;
        used[idx] = 1;
    }

    cout << ans << endl;

    return 0;
}