#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long best_sum = LLONG_MIN;
    std::vector<int> best_removed;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                std::vector<int> removed;
                long long sum = 0;
                for (int k = 0; k < n; ++k) {
                    if (k > i && k < j) {
                        removed.push_back(k + 1);
                    } else {
                        sum += a[k];
                    }
                }

                if (sum > best_sum && removed.size() + 2 <= n) {
                    best_sum = sum;
                    best_removed = removed;
                    if (i > 0) {
                        for (int k = 0; k < i; ++k) {
                            best_removed.push_back(k + 1);
                        }
                    }
                    if (j < n - 1) {
                        for (int k = j + 1; k < n; ++k) {
                            best_removed.push_back(k + 1);
                        }
                    }
                }
            }
        }
    }

    std::cout << best_sum << " " << best_removed.size() << std::endl;
    for (int i = 0; i < best_removed.size(); ++i) {
        std::cout << best_removed[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}