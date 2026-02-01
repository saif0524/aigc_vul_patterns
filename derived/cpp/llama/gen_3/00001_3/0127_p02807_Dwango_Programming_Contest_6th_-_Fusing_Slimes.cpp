#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int N;
   vironments:
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            ans = (ans + (X[j + 1] - X[j]) * (N - 1 - i)) % MOD;
        }
    }

    for (int i = 1; i <= N - 1; i++) {
        ans = (ans * i) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}