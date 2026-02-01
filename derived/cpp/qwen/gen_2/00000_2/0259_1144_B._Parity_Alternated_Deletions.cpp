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
    std::vector<int> even, odd;
    for (int x : a) {
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }
    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());
    int result = 0;
    if (even.size() > odd.size()) {
        result += even[0];
        for (int i = 1; i < odd.size(); ++i) {
            result += std::min(even[i * 2], odd[i]);
        }
    } else if (odd.size() > even.size()) {
        result += odd[0];
        for (int i = 1; i < even.size(); ++i) {
            result += std::min(odd[i * 2], even[i]);
        }
    } else {
        for (int i = 0; i < even.size(); ++i) {
            result += std::min(even[i], odd[i]);
        }
    }
    std::cout << result;
}