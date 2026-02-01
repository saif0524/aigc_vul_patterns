#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 5000005;
bool busy[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        ll s, d;
        cin >> s >> d;

        bool ok = true;
        for (int i = s; i < s + d; i++) {
            if (busy[i]) {
                ok = false;
                break;
            }
        }

        ll start = -1;
        if (ok) {
            start = s;
        } else {
            ll x = 1;
            while (true) {
                bool found = true;
                for (int i = x; i < x + d; i++) {
                    if (busy[i]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    start = x;
                    break;
                }
                x++;
            }
        }

        for (int i = start; i < start + d; i++) {
            busy[i] = true;
        }

        cout << start << " " << start + d - 1 << "\n";
    }

    return 0;
}