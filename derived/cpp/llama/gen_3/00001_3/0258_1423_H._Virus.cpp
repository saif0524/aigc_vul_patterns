#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x]!= x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX!= rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<UnionFind> uf(k, UnionFind(n));
    queue<pair<int, pair<int, int>>> contacts;
    int day = 0;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            contacts.push({day, {x, y}});
        } else if (t == 2) {
            int z;
            cin >> z;
            z--;
            int root = uf[day % k].find(z);
            cout << uf[day % k].size[root] << endl;
        } else {
            day++;
            if (day >= k) {
                int d = day - k;
                while (!contacts.empty() && contacts.front().first == d) {
                    int x = contacts.front().second.first;
                    int y = contacts.front().second.second;
                    contacts.pop();
                    uf[d % k].unionSet(x, y);
                }
            }
        }
    }

    return 0;
}