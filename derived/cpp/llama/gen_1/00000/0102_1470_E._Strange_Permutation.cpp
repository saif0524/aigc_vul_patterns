#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;

const int INF = 1e9;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vi> perm;
    perm.push_back(p);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i <= c) {
                vi ne = p;
                reverse(ne.begin() + i, ne.begin() + j + 1);
                bool ok = true;
                for (int k = 0; k < perm.size(); k++) {
                    if (ne == perm[k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    perm.push_back(ne);
                }
            }
        }
    }
    sort(perm.begin(), perm.end());
    while (q--) {
        ll pos, ind;
        cin >> pos >> ind;
        pos -= 1;
        ind -= 1;
        if (ind >= perm.size()) {
            cout << "-1\n";
            continue;
        }
        cout << perm[ind][pos] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}