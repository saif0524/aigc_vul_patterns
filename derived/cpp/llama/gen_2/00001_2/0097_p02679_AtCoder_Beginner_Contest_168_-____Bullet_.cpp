#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long inv(long long n, long long p) {
    return power(n, p - 2, p);
}

long long nCrModPFermat(int n, int r, long long p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * inv(fac[r], p) % p * inv(fac[n - r], p) % p) % p;
}

vector<int> topoSort(int v, vector<vector<int>>& adj) {
    vector<int> order;
    vector<int> visited(v);
    function<void(int)> dfs = [&](int node) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it);
            }
        }
        order.push_back(node);
    };
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] * A[j] + B[i] * B[j] == 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<long long> dp(N, 0);
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (auto it : adj[i]) {
            dp[i] = (dp[i] + MOD - dp[it]) % MOD;
        }
    }
    long long ans = 0;
    for (auto it : dp) {
        ans = (ans + it) % MOD;
    }
    ans = (ans + 1) % MOD;
    cout << ans << "\n";
    return 0;
}