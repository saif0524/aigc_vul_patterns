#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int k1;
        cin >> k1;
        vector<int> x(k1);
        for (auto& xi : x) {
            cin >> xi;
            --xi;
        }
        int k2;
        cin >> k2;
        vector<int> y(k2);
        for (auto& yi : y) {
            cin >> yi;
            --yi;
        }

        map<int, int> my_to_his;
        map<int, int> his_to_my;

        int query(int type, int val) {
            if (type == 0) {
                if (my_to_his.count(val)) {
                    return my_to_his[val];
                } else {
                    cout << "A " << val + 1 << endl;
                    int res;
                    cin >> res;
                    --res;
                    my_to_his[val] = res;
                    return res;
                }
            } else {
                if (his_to_my.count(val)) {
                    return his_to_my[val];
                } else {
                    cout << "B " << val + 1 << endl;
                    int res;
                    cin >> res;
                    --res;
                    his_to_my[val] = res;
                    return res;
                }
            }
        }

        int x_root = x[0];
        for (int xi : x) {
            if (g[xi].size() < g[x_root].size()) {
                x_root = xi;
            }
        }

        int y_root = y[0];
        for (int yi : y) {
            if (his_to_my.count(yi)) {
                cout << "C " << his_to_my[yi] + 1 << endl;
                goto next_test;
            }
        }

        for (int yi : y) {
            int my_yi = query(1, yi);
            if (find(x.begin(), x.end(), my_yi) != x.end()) {
                cout << "C " << my_yi + 1 << endl;
                goto next_test;
            }
        }

        int my_x_root = x_root;
        int his_x_root = query(0, x_root);
        if (find(y.begin(), y.end(), his_x_root) != y.end()) {
            cout << "C " << x_root + 1 << endl;
            goto next_test;
        }

        for (int neighbor : g[x_root]) {
            int his_xi = query(0, neighbor);
            if (find(y.begin(), y.end(), his_xi) != y.end()) {
                cout << "C " << neighbor + 1 << endl;
                goto next_test;
            }
        }

        cout << "C -1" << endl;
        next_test:;
    }

    return 0;
}