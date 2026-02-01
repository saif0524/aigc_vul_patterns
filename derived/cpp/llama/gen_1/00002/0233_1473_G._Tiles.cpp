#include <iostream>
#include <vector>
#include <cstdint>

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
    return (static_cast<int64_t>(a) * b) % MOD;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }

    int tiles = 1;
    std::vector<int> paths(1, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            std::vector<int> new_paths(tiles + 1);
            for (int k = 0; k < tiles; ++k) {
                new_paths[k] = add(new_paths[k], paths[k]);
                new_paths[k + 1] = add(new_paths[k + 1], paths[k]);
            }
            paths = new_paths;
            ++tiles;
        }

        for (int j = 0; j < b[i]; ++j) {
            std::vector<int> new_paths(tiles - 1);
            for (int k = 0; k < tiles - 1; ++k) {
                new_paths[k] = add(paths[k], paths[k + 1]);
            }
            paths = new_paths;
            --tiles;
        }
    }

    int ans = 0;
    for (int i = 0; i < tiles; ++i) {
        ans = add(ans, paths[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}