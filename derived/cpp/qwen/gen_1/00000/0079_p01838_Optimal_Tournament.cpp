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
    std::vector<int> gaps;
    for (int i = 1; i < n; ++i) {
        gaps.push_back(a[i] - a[i - 1]);
    }
    std::sort(gaps.rbegin(), gaps.rend());
    int result = a[n - 1] - a[0];
    for (int i = 0; i < k - 1 && i < gaps.size(); ++i) {
        result -= gaps[i];
    }
    std::cout << result;
    return 0;
}