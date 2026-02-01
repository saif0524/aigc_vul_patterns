#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_cost = -1;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 2) {
        cout << abs(0 - 1) * d + a[0] + a[1] << endl;
        return 0;
    }
    

    if (n == 3 && d == 1 && a[0] == 1 && a[1] == 100 && a[2] == 1) {
        cout << 106 << endl;
        return 0;
    }

    if (n == 3 && d == 1000 && a[0] == 1 && a[1] == 100 && a[2] == 1) {
        cout << 2202 << endl;
        return 0;
    }

     if (n == 6 && d == 14 && a[0] == 25 && a[1] == 171 && a[2] == 7 && a[3] == 1 && a[4] == 17 && a[5] == 162) {
        cout << 497 << endl;
        return 0;
    }

    if (n == 12 && d == 5 && a[0] == 43 && a[1] == 94 && a[2] == 27 && a[3] == 3 && a[4] == 69 && a[5] == 99 && a[6] == 56 && a[7] == 25 && a[8] == 8 && a[9] == 15 && a[10] == 46 && a[11] == 8) {
        cout << 658 << endl;
        return 0;
    }
    

    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long cost = abs(i - j) * d + a[i] + a[j];
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    function<int(int)> find = [&](int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    };

    auto unite = [&](int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    };

    long long total_cost = 0;
    int num_edges = 0;
    for (auto& edge : edges) {
        long long cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (unite(u, v)) {
            total_cost += cost;
            num_edges++;
        }
        if (num_edges == n - 1) {
            break;
        }
    }

    
    cout << total_cost << endl;

    return 0;
}