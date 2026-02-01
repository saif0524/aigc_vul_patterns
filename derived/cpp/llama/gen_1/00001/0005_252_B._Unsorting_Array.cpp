#include <iostream>
#include <vector>
#include <algorithm>

bool isSorted(const std::vector<int>& a) {
    bool isAscending = true;
    bool isDescending = true;

    for (int i = 1; i < a.size(); ++i) {
        if (a[i] < a[i - 1]) {
            isAscending = false;
        }
        if (a[i] > a[i - 1]) {
            isDescending = false;
        }
    }

    return isAscending || isDescending;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] != a[j]) {
                swap(a[i], a[j]);
                if (!isSorted(a)) {
                    std::cout << i + 1 << " " << j + 1 << std::endl;
                    return 0;
                }
                swap(a[i], a[j]);
            }
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}