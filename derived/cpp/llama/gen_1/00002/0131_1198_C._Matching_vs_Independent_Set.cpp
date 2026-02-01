#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    set<int> indSet;
    vector<int> matching;

    for (int i = 1; i <= 3 * n; i++) {
        indSet.insert(i);
    }

    for (int i = 0; i < m; i++) {
        if (indSet.count(edges[i].first) && indSet.count(edges[i].second)) {
            matching.push_back(i + 1);
            indSet.erase(edges[i].first);
            indSet.erase(edges[i].second);
        }
    }

    if (matching.size() == n) {
        cout << "Matching\n";
        for (int i : matching) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << "IndSet\n";
        int k = 0;
        for (int i : indSet) {
            if (k == n) break;
            cout << i << ' ';
            k++;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}