#include <iostream>
#include <vector>

int main() {
    int n, m, c;
    std::cin >> n >> m >> c;
    
    std::vector<int> a(n);
    std::vector<int> b(m);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    for (int step = 0; step < n - m + 1; ++step) {
        for (int i = 0; i < m; ++i) {
            a[step + i] = (a[step + i] + b[i]) % c;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
        if (i < n - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    return 0;
}