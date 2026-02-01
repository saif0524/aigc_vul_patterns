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

    std::vector<int> B = A;
    std::sort(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        if (A[i] == B[N - 1]) {
            std::cout << B[N - 2] << std::endl;
        } else {
            std::cout << B[N - 1] << std::endl;
        }
    }

    return 0;
}