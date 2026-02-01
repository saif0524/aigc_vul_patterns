#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int xor_val = 0;
    for (int i = 0; i < N; i++) {
        xor_val ^= A[i];
    }

    int min_val = *std::min_element(A.begin(), A.end());

    std::vector<int> cnt(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cnt[A[i] - min_val + 1] = 1;
    }

    int prefix_xor = 0;
    int cnt_zero = 0;
    for (int i = 1; i <= N; i++) {
        prefix_xor ^= (i - cnt[i]);
        if (prefix_xor == 0) {
            cnt_zero++;
        }
    }

    if (cnt_zero == N - min_val + 1) {
        if (min_val % 2 == 0) {
            std::cout << "Second" << std::endl;
        } else {
            std::cout << "First" << std::endl;
        }
        return 0;
    }

    if (xor_val == 0) {
        std::cout << "Second" << std::endl;
    } else {
        std::cout << "First" << std::endl;
    }

    return 0;
}