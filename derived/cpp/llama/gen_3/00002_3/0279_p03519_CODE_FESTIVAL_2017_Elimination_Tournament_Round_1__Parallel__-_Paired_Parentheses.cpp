#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(2 * N);
    vector<ll> b(2 * N);
    for (ll& val : a) cin >> val;
    for (ll& val : b) cin >> val;

    for (int q = 0; q < Q; q++) {
        int p;
        ll x, y;
        cin >> p >> x >> y;
        p--;
        a[p] = x;
        b[p] = y;

        ll mx = 0;
        for (int i = 0; i < N; i++) {
            mx += max(a[i * 2], b[i * 2]) + max(a[i * 2 + 1], b[i * 2 + 1]);
        }
        cout << mx << endl;
    }

    return 0;
}