#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int &a : A) std::cin >> a;
    
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int b, e, t;
        std::cin >> b >> e >> t;
        std::rotate(A.begin() + b, A.begin() + e, A.begin() + t + (e - b));
    }
    
    for (size_t i = 0; i < A.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << A[i];
    }
    std::cout << '\n';
    return 0;
}