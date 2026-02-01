#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    int swapCount = 0;
    for (int i = 0; i < N - 1; ++i) {
        int mini = i;
        for (int j = i + 1; j < N; ++j) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            std::swap(A[i], A[mini]);
            ++swapCount;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        std::cout << A[i] << (i < N - 1 ? ' ' : '\n');
    }
    std::cout << swapCount << '\n';
    
    return 0;
}