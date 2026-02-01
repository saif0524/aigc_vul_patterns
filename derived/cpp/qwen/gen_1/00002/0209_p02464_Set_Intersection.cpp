#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> A(n);
    for (int &x : A) std::cin >> x;
    std::cin >> m;
    std::vector<int> B(m);
    for (int &x : B) std::cin >> x;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            std::cout << A[i] << '\n';
            ++i;
            ++j;
        } else if (A[i] < B[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return 0;
}