#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> f(const std::vector<int>& p, int k) {
    std::vector<int> result;
    int r = p.size() / k;
    for (int i = 0; i < r; i++) {
        for (int j = i * k + 1; j < (i + 1) * k; j++) {
            result.push_back(p[j]);
        }
        result.push_back(p[i * k]);
    }
    if (p.size() % k != 0) {
        for (int j = r * k; j < p.size(); j++) {
            result.push_back(p[j]);
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    for (int i = 2; i <= n; i++) {
        p = f(p, i);
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << p[i];
    }
    std::cout << std::endl;
    return 0;
}