#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> genre_count(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int genre;
        std::cin >> genre;
        genre_count[genre]++;
    }
    
    long long result = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            result += static_cast<long long>(genre_count[i]) * genre_count[j];
        }
    }
    
    std::cout << result << std::endl;
    return 0;
}