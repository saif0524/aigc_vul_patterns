#include <iostream>
#include <vector>
#include <algorithm>

void findIntersection(const std::vector<int>& A, const std::vector<int>& B) {
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            std::cout << A[i] << std::endl;
            i++;
            j++;
        }
    }
}

int main() {
    int n, m;

    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::cin >> m;
    std::vector<int> B(m);
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    findIntersection(A, B);

    return 0;
}