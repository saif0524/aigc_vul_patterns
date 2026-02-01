#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int &x : A) std::cin >> x;

    int swaps = 0;
    for (int i = 0; i < n - 1; ++i) {
        int mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            std::swap(A[i], A[mini]);
            ++swaps;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << A[i];
        if (i < n - 1) std::cout << ' ';
    }
    std::cout << '\n' << swaps << '\n';

    return 0;
}