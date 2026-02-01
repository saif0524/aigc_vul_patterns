#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());

    int sum_even = std::accumulate(even.begin(), even.end(), 0);
    int sum_odd = std::accumulate(odd.begin(), odd.end(), 0);

    int ans = 2000000000;

    if (even.size() == odd.size()) {
        ans = std::min(ans, sum_even + sum_odd - even.back() - odd.back());
    }

    if (even.size() > odd.size()) {
        int diff = even.size() - odd.size();
        int sum = 0;
        for (int i = 0; i < diff; ++i) {
            sum += even[i];
        }
        ans = std::min(ans, sum + sum_odd);
    }

    if (odd.size() > even.size()) {
        int diff = odd.size() - even.size();
        int sum = 0;
        for (int i = 0; i < diff; ++i) {
            sum += odd[i];
        }
        ans = std::min(ans, sum + sum_even);
    }

    if (even.size() == odd.size() + 1) {
        int sum = 0;
        for (int i = 0; i < odd.size(); ++i) {
            sum += even[i];
        }
        sum += even.back();
        ans = std::min(ans, sum + sum_odd - odd.back());
    }

    if (odd.size() == even.size() + 1) {
        int sum = 0;
        for (int i = 0; i < even.size(); ++i) {
            sum += odd[i];
        }
        sum += odd.back();
        ans = std::min(ans, sum + sum_even - even.back());
    }

    std::cout << ans << std::endl;

    return 0;
}