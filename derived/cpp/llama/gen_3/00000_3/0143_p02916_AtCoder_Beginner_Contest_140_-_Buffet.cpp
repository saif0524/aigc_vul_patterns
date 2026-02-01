#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> C(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> C[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += B[A[i] - 1];
    }

    for (int i = 0; i < N - 1; i++) {
        ans += C[i];
    }

    std::cout << ans << std::endl;

    return 0;
}