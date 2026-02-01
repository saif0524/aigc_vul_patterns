#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result += a[i];
    }
    std::cout << result;
    return 0;
}