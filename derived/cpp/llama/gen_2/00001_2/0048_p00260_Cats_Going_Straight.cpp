#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2'000'000'000;
const int MAXN = 20;

typedef long long ll;

int n;
int x[MAXN], y[MAXN];
int d[MAXN][MAXN];

bool in(int i, int j, int k) {
    ll z = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
    return z >= 0;
}

bool out(int i, int j, int k) {
    ll z = (x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i]);
    return z >= 0;
}

bool cmp(int i, int j) {
    if (x[i] != x[j])
        return x[i] < x[j];
    return y[i] < y[j];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        if (!in(i, j, k) || in(j, k, i)) {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    while (true) {
        solve();
        if (cin.peek() == '0')
            break;
    }

    return 0;
}