#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;

    int n = s.size();
    vector<string> options(n + 1);
    for (int i = 0; i <= n; i++) {
        options[i] = s.substr(0, i) + t + s.substr(i);
    }

    for (int i = 0; i < q; i++) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;

        string best = "";
        int bestIndex = -1;
        for (int j = l; j <= r; j++) {
            if (x <= (j % k) && (j % k) <= y) {
                if (best.empty() || options[j] < best) {
                    best = options[j];
                    bestIndex = j;
                }
            }
        }

        cout << bestIndex << endl;
    }

    return 0;
}