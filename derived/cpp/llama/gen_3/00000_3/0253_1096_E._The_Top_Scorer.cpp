#include <iostream>
#include <vector>
#include <numeric>

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

int mul(int a, int b) {
    return static_cast<int>(static_cast<long long>(a) * b % MOD);
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return powmod(a, MOD - 2);
}

int C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    static std::vector<int> fact = {1};
    while (fact.size() <= n) {
        fact.push_back(mul(fact.back(), fact.size()));
    }
    return mul(fact[n], mul(inv(fact[k]), inv(fact[n - k])));
}

int F(int n, int k) {
    static std::vector<std::vector<int>> memo = {{1}};
    while (memo.size() <= n) {
        memo.push_back({});
    }
    if (memo[n].size() <= k) {
        memo[n].resize(k + 1);
    }
    if (memo[n][k] != 0) {
        return memo[n][k];
    }
    if (n == 0) {
        memo[n][k] = (k == 0);
    } else {
        for (int i = 0; i <= k; ++i) {
            memo[n][k] = add(memo[n][k], mul(C(k, i), F(n - 1, k - i)));
        }
    }
    return memo[n][k];
}

int main() {
    int p, s, r;
    std::cin >> p >> s >> r;
    int num = 0;
    for (int i = r; i <= s; ++i) {
        int cnt = 0;
        for (int j = 0; j <= i; ++j) {
            cnt = add(cnt, F(p - 1, i - j - 1));
        }
        num = add(num, cnt);
    }
    int den = F(p, s);
    std::cout << mul(num, inv(den)) << std::endl;
    return 0;
}