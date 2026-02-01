#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 10;

int n, x[N], y[N];
int b[N];
string ans;

bool check() {
    int suna = 0, sung = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            suna += x[i];
        } else {
            sung += y[i];
        }
    }
    if (abs(suna - sung) > 500) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        b[i] = (x[i] > y[i]);
    }

    do {
        if (check()) {
            for (int i = 0; i < n; ++i) {
                ans += (b[i] ? 'A' : 'G');
            }
            cout << ans << endl;
            return 0;
        }
    } while (next_permutation(b, b + n));

    cout << -1 << endl;

    return 0;
}