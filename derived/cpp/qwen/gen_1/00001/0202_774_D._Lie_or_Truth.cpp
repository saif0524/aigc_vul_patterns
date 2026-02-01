#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    
    std::vector<int> sub_a(a.begin() + l - 1, a.begin() + r);
    std::vector<int> sub_b(b.begin() + l - 1, b.begin() + r);
    
    std::sort(sub_a.begin(), sub_a.end());
    std::sort(sub_b.begin(), sub_b.end());
    
    if (sub_a == sub_b) {
        std::cout << "TRUTH";
    } else {
        std::cout << "LIE";
    }
    
    return 0;
}