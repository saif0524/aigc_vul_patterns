#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return power(a, MOD - 2);
}

long long C(long long n, long long k, const vector<long long>& fact, const vector<long long>& invFact) {
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> intervals(n);
    for (auto& [l, r] : intervals) {
        cin >> l >> r;
    }

    sort(begin(intervals), end(intervals));

    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        L[i] = intervals[i].first;
        R[i] = intervals[i].second;
    }

    vector<int> lcp(n), rcp(n);
    for (int i = 0; i < n; ++i) {
        lcp[i] = i;
        while (lcp[i] < n - 1 && L[lcp[i] + 1] <= R[i]) ++lcp[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        rcp[i] = i;
        while (rcp[i] > 0 && R[rcp[i] - 1] >= L[i]) --rcp[i];
    }

    vector<int> start(n), end(n);
    for (int i = 0; i < n; ++i) {
        start[i] = rcp[i];
        end[i] = lcp[i];
    }

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        ++cnt[start[i]];
        --cnt[end[i] + 1];
    }

    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
    }

    vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = inv(fact[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] >= k) {
            ans = (ans + C(cnt[i], k, fact, invFact)) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}