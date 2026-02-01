#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int b, e, t;
        std::cin >> b >> e >> t;

        for (int k = 0; k < e - b; k++) {
            int temp = A[b + k];
            A[b + k] = A[t + k];
            A[t + k] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}