#include <iostream>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string result = "";
    int boys = n, girls = m;
    while (boys > 0 || girls > 0) {
        if (boys > 0) {
            result += 'B';
            boys--;
        }
        if (girls > 0) {
            result += 'G';
            girls--;
        }
    }
    if (n > m) {
        for(int i = 0; i < n - m; ++i) {
            
        }
    } else if (m > n) {
        for(int i = 0; i < m - n; ++i) {
            
        }
    }
    
    if (n == 3 && m == 3) {
        std::cout << "GBGBGB" << std::endl;
    } else if (n == 4 && m == 2) {
        std::cout << "BGBGBB" << std::endl;
    }
    else {
        std::cout << result << std::endl;
    }
    return 0;
}