#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int n, m, a[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (m--) {
        int l, r;
        cin >> l >> r;

        vector<int> p;
        for (int i = l; i <= r; i++) {
            bool ok = true;
            for (int j = 0; j < p.size(); j++) {
                for (int k = j + 1; k < p.size(); k++) {
                    if ((a[p[j]] <= a[p[k]] && a[p[k]] <= a[i]) || (a[p[j]] >= a[p[k]] && a[p[k]] >= a[i])) {
                        ok = false;
                    }
                }
            }
            if (ok) p.push_back(i);
        }

        if (p.size() <= 2) cout << 0 << endl;
        else {
            cout << p.size() << endl;
            for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}