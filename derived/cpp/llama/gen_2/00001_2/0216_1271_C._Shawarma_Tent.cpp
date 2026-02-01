#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class SegmentTree {
public:
    struct Node {
        int x, y, count;
    };

    vector<Node> tree;

    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    Node combine(const Node& a, const Node& b) {
        Node res;
        res.x = max(a.x, b.x);
        res.y = max(a.y, b.y);
        res.count = a.count + b.count;
        return res;
    }

    void build(const vector<Node>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = a[lx];
        } else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void build(const vector<Node>& a) {
        build(a, 0, 0, a.size());
    }

    Node get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {0, 0, 0};
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        return combine(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }

    Node get(int l, int r) {
        return get(l, r, 0, 0, tree.size() / 4);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sx, sy;
    cin >> n >> sx >> sy;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    set<int> xs, ys;
    for (int i = 0; i < n; ++i) {
        int dist = abs(x[i] - sx) + abs(y[i] - sy);
        xs.insert(x[i] + y[i] - dist / 2);
        xs.insert(x[i] + y[i] - (dist + 1) / 2);
        ys.insert(x[i] - y[i] + dist / 2);
        ys.insert(x[i] - y[i] + (dist + 1) / 2);
    }

    map<int, int> toIndexX, toIndexY;
    vector<int> fromIndexX, fromIndexY;
    int cntX = 0, cntY = 0;
    for (int x : xs) {
        toIndexX[x] = cntX;
        fromIndexX.push_back(x);
        cntX++;
    }
    for (int y : ys) {
        toIndexY[y] = cntY;
        fromIndexY.push_back(y);
        cntY++;
    }

    vector<int> dsu(cntX + cntY);
    for (int i = 0; i < cntX + cntY; ++i) dsu[i] = i;

    int find(int x) {
        if (dsu[x] != x) dsu[x] = find(dsu[x]);
        return dsu[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) dsu[x] = y;
    }

    for (int i = 0; i < n; ++i) {
        int x1 = toIndexX[x[i] + y[i] - abs(x[i] - sx) - abs(y[i] - sy)];
        int y1 = toIndexY[x[i] - y[i] + abs(x[i] - sx) + abs(y[i] - sy)];
        unite(x1, y1 + cntX);
        x1 = toIndexX[x[i] + y[i] - abs(x[i] - sx) - abs(y[i] - sy) + 1];
        y1 = toIndexY[x[i] - y[i] + abs(x[i] - sx) + abs(y[i] - sy) - 1];
        unite(x1, y1 + cntX);
    }

    int bestAnswer = 0;
    pair<int, int> answer;
    for (auto x : xs) {
        for (auto y : ys) {
            int i = toIndexX[x];
            int j = toIndexY[y] + cntX;
            if (find(i) == find(j)) {
                int ans = 0;
                for (int k = 0; k < n; ++k) {
                    if ((x - (x[k] + y[k] - abs(x[k] - sx) - abs(y[k] - sy))) % 2 == 0
                        && y == x[k] - y[k] + abs(x[k] - sx) + abs(y[k] - sy)) {
                        ans++;
                    }
                }
                if (ans > bestAnswer) {
                    bestAnswer = ans;
                    answer = {x, y};
                }
            }
        }
    }

    cout << bestAnswer << '\n';
    cout << (answer.first + answer.second + abs(sx - answer.first) + abs(sy - answer.second)) / 2 << ' '
         << (answer.second - answer.first + abs(sx - answer.first) + abs(sy - answer.second)) / 2 << '\n';

    return 0;
}