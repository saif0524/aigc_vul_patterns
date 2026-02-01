#include <iostream>
#include <map>

std::map<int, int> f;

int calculate_f(int n) {
    if (f.find(n) != f.end()) return f[n];
    if (n <= 2) return 0;
    int result = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int max_len = std::max({i, j, n - i - j});
            int min_len = std::min({i, j, n - i - j});
            int mid_len = n - max_len - min_len;
            result = std::max(result, 1 + calculate_f(mid_len));
        }
    }
    f[n] = result;
    return result;
}

int main() {
    int x;
    std::cin >> x;
    int n = 2;
    while (true) {
        if (calculate_f(n) == x) break;
        n++;
    }
    int result = n;
    while (true) {
        n++;
        if (calculate_f(n) != x) break;
        result = n;
    }
    std::cout << result << std::endl;
    return 0;
}