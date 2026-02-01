#include <iostream>
#include <string>
#include <vector>

const int mod = 1e9 + 7;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> C(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    int ans = 0;
    for (int i = k; i <= n - 1; i++) {
        int coef = C[n - 1][k];
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n - 1) {
                if ((i & 1) == (j & 1)) {
                    cur = (cur + static_cast<int>(s[j] - '0') * coef) % mod;
                }
            } else {
                if ((i & 1) == (j & 1)) {
                    cur = (cur + static_cast<int>(s[j] - '0') * coef * 10) % mod;
                } else {
                    cur = (cur + static_cast<int>(s[j] - '0') * coef) % mod;
                }
            }
        }
        ans = (ans + cur) % mod;
    }

    std::cout << ans << std::endl;

    return 0;
}