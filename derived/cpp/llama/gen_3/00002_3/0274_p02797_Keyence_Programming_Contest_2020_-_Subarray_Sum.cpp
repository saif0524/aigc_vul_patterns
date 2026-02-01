#include <iostream>
#include <vector>

int main() {
    int N, K, S;
    std::cin >> N >> K >> S;

    std::vector<int> A(N, 1);
    int start = 0;
    int end = N - 1;
    while (K > 0) {
        int add = (S > 1) ? S - 1 : 1;
        A[start] += add;
        K -= (end - start + 1);
        start++;
        if (K < 0) {
            A[start - 1] -= -K;
            K = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}