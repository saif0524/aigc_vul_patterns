#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, tokens;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Edge> edges(k);
    vector<int> degree(n, 0);
    vector<int> personalToken(n, 1);

    for (int i = 0; i < k; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].u--; edges[i].v--;
        edges[i].tokens = 2;
        degree[edges[i].u]++;
        degree[edges[i].v]++;
    }

    for (int i = 0; i < k; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (degree[u] == degree[v]) {
            if (personalToken[u] == personalToken[v]) {
                personalToken[u] = 0;
            } else if (personalToken[u] == 0) {
                personalToken[v] = 0;
            } else {
                personalToken[u] = 0;
            }
        } else if (degree[u] < degree[v]) {
            if (personalToken[u] == 1) {
                personalToken[u] = 0;
                edges[i].tokens = 1;
            }
        } else {
            if (personalToken[v] == 1) {
                personalToken[v] = 0;
                edges[i].tokens = 1;
            }
        }
        degree[u] += edges[i].tokens;
        degree[v] += edges[i].tokens;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += personalToken[i];
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        if (personalToken[i] == 1) cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < k; i++) {
        cout << edges[i].u + 1 << " " << edges[i].v + 1 << " " << edges[i].tokens << endl;
    }

    return 0;
}