#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200005;

int n, m, grid[MAX_N], parent[MAX_N], rank[MAX_N];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        return false;
    }

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }

    return true;
}

bool isValid(int l, int r) {
    for (int i = 1; i <= n * m; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (l <= grid[i * m + j] && grid[i * m + j] <= r) {
                if (i > 0 && l <= grid[(i - 1) * m + j] && grid[(i - 1) * m + j] <= r) {
                    if (!unionSet(grid[i * m + j], grid[(i - 1) * m + j])) {
                        return false;
                    }
                    edgeCount++;
                }
                if (j > 0 && l <= grid[i * m + j - 1] && grid[i * m + j - 1] <= r) {
                    if (!unionSet(grid[i * m + j], grid[i * m + j - 1])) {
                        return false;
                    }
                    edgeCount++;
                }
            }
        }
    }

    int nodeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (l <= grid[i * m + j] && grid[i * m + j] <= r) {
                nodeCount++;
            }
        }
    }

    return nodeCount == 0 || edgeCount == nodeCount - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i * m + j];
        }
    }

    int count = 0;
    for (int l = 1; l <= n * m; l++) {
        for (int r = l; r <= n * m; r++) {
            if (isValid(l, r)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}