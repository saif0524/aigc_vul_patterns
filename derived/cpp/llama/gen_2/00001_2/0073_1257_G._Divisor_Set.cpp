#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;

long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[p[i]]++;
    }
    map<int, vector<int>> G;
    vector<int> v;
    for (auto& e : cnt) {
        v.push_back(e.second);
    }
    int k = v.size();
    for (int i = 0; i < k; i++) {
        G[v[i]].push_back(i);
    }
    vector<vector<long long>> dp(k + 1, vector<long long>(v.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= v.size(); j++) {
            if (dp[i][j] == 0) continue;
            for (int x = 0; x <= v[i]; x++) {
                if (x == 0 && j > 0) continue;
                int y = j;
                if (x == 0) y--;
                if (y < 0) continue;
                dp[i + 1][y] = (dp[i + 1][y] + dp[i][j] * modPow(2, x)) % MOD;
            }
        }
    }
    cout << dp[k][0] << endl;
    return 0;
}