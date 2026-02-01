#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int pow_mod(int a, int b) {
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

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> mat(n, std::vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        --a;
        --b;
        mat[a][b] = mat[b][a] = c;
    }

    int ans = 1;
    for (int k = 0; k < n; ++k) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mat[i][k] == -1) {
                ++cnt;
            }
        }

        if (cnt == 0) {
            continue;
        }

        bool can_love = true;
        bool can_hate = true;
        for (int i = 0; i < n; ++i) {
            if (mat[i][k] == 1) {
                can_hate = false;
            } else if (mat[i][k] == 0) {
                can_love = false;
            }
        }

        if (can_love && can_hate) {
            ans = mul(ans, pow_mod(2, cnt));
        } else if (can_love || can_hate) {
            ans = mul(ans, pow_mod(2, cnt - 1));
        } else {
            ans = 0;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}