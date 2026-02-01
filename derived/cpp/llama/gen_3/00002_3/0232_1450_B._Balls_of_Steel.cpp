#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    UnionFind(int size) : parent(size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; i++) {
            cin >> P[i].first >> P[i].second;
        }
        UnionFind uf(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (abs(P[i].first - P[j].first) + abs(P[i].second - P[j].second) <= K) {
                    uf.parent[uf.find(j)] = uf.find(i);
                }
            }
        }
        vector<int> roots;
        for (int i = 0; i < N; i++) {
            roots.push_back(uf.find(i));
        }
        if (count(roots.begin(), roots.end(), roots[0]) == N) {
            cout << 1 << endl;
        } else {
            bool flag = false;
            for (int i = 0; i < N; i++) {
                int root = uf.find(i);
                for (int j = 0; j < N; j++) {
                    int other_root = uf.find(j);
                    if (root != other_root && abs(P[i].first - P[j].first) + abs(P[i].second - P[j].second) <= K) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}