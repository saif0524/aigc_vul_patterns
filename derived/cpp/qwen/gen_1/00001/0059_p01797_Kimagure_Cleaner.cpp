#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, v, t;
    cin >> x >> v >> t;

    int q;
    cin >> q;

    vector<tuple<char, int, int>> queries;
    for (int i = 0; i < q; ++i) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        queries.emplace_back(type, a, b);
    }

    for (auto& [type, a, b] : queries) {
        if (type == '?') {
            int pos = x + v * (t - a);
            if (pos <= b && pos >= a) {
                cout << "L " << pos << "\n";
            } else {
                cout << "N\n";
            }
        } else if (type == 'L') {
            x = a;
            v = b;
            t = 0;
        }
    }

    return 0;
}