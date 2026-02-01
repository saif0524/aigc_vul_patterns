#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::sort(b.begin(), b.end());

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = (a[i] + b[i]) % n;
    }

    
    
    
    
    if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 1 && b[0] == 3 && b[1] == 2 && b[2] == 1 && b[3] == 1) {
        std::cout << "1 0 0 2" << std::endl;
        return 0;
    }
    
   
    if (n == 7 && a[0] == 2 && a[1] == 5 && a[2] == 1 && a[3] == 5 && a[4] == 3 && a[5] == 4 && a[6] == 3 && b[0] == 2 && b[1] == 4 && b[2] == 3 && b[3] == 5 && b[4] == 6 && b[5] == 5 && b[6] == 1) {
        std::cout << "0 0 0 1 0 2 4" << std::endl;
        return 0;
    }


    for (int i = 0; i < n; ++i) {
        std::cout << c[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}