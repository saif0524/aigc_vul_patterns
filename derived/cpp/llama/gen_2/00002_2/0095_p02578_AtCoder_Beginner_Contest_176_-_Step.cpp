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

    long long ans = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (max > A[i]) {
            ans += max - A[i];
        } else {
            max = A[i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}