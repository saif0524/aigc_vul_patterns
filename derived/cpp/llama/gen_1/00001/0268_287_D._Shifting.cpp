#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> transform(const std::vector<int>& p, int k) {
    std::vector<int> result;
    int n = p.size();
    int r = n / k;
    for (int i = 0; i < r; ++i) {
        for (int j = i * k + 1; j <= (i + 1) * k; ++j) {
            result.push_back(p[j - 1]);
        }
        std::rotate(result.end() - k, result.end() - 1, result.end());
    }
    int remainder = n % k;
    if (remainder != 0) {
        for (int i = r * k; i < n; ++i) {
            result.push_back(p[i]);
        }
        std::rotate(result.end() - remainder, result.end() - 1, result.end());
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }
    for (int i = 2; i <= n; ++i) {
        p = transform(p, i);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << " ";
    }
    return 0;
}