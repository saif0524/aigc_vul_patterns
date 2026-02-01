#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int find(int x, int parent[]) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unionSet(int x, int y, int parent[], int rank[]) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            edges[i][j] = x - 1;
        }
    }

    int parent[m];
    for (int i = 0; i < m; i++) {
        parent[i] = i;
    }

    int rank[m] = {0};

    vector<int> included(n, 0);
    for (int i = 0; i < n; i++) {
        if (edges[i][0] == edges[i][1]) {
            continue;
        }
        if (find(edges[i][0], parent) != find(edges[i][1], parent)) {
            unionSet(edges[i][0], edges[i][1], parent, rank);
            included[i] = 1;
        }
    }

    int result = 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        result = (1LL * result * 2) % mod;
    }

    cout << result << " " << count << "\n";

    for (int i = 0; i < n; i++) {
        if (included[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}