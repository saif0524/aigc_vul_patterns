#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> h(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    map<int, int> count;
    for (int i = 0; i < 2 * N; i++) {
        count[h[i]]++;
    }

    int M = 1;
    for (int i = 1; i <= N; i++) {
        M = (1LL * M * i) % MOD;
    }

    vector<int> fac(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }

    vector<int> invFac(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        invFac[i] = (1LL * invFac[i - 1] * (MOD - MOD / i)) % MOD;
        while (invFac[i] < 0) {
            invFac[i] += MOD;
        }
    }

    int ans = 1;
    for (auto& c : count) {
        if (c.second > N) {
            ans = (1LL * ans * fac[c.second / 2]) % MOD;
            ans = (1LL * ans * invFac[N - c.second / 2]) % MOD;
        } else {
            ans = 0;
            break;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
        return 0;
    }

    ans = (1LL * ans * M) % MOD;

    for (int i = 2 * N - 1; i >= 1; i--) {
        if (h[i] == h[i - 1]) {
            ans = (1LL * ans * i) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}