#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N), B(N), C(N-1);
    for (int i = 0; i < N; ++i) std::cin >> A[i];
    for (int i = 0; i < N; ++i) std::cin >> B[i];
    for (int i = 0; i < N-1; ++i) std::cin >> C[i];
    
    int satisfaction = 0;
    for (int i = 0; i < N; ++i) {
        satisfaction += B[A[i] - 1];
        if (i < N - 1) {
            if (A[i] + 1 == A[i + 1]) satisfaction += C[A[i] - 1];
        }
    }
    
    std::cout << satisfaction << std::endl;
    return 0;
}