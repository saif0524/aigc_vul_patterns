#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<long long> S(N + 1, 0);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }

    long long ans = 0;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            if ((S[r + 1] - S[l]) % M == 0) {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}