#include <iostream>
#include <vector>
#include <algorithm>

bool canBeSortedUsingRavioliSort(std::vector<int>& a) {
    int n = a.size();
    std::vector<int> sortedA = a;
    std::sort(sortedA.begin(), sortedA.end());

    while (!a.empty()) {
        // Check for sliding ravioli
        for (int i = 0; i < (int)a.size() - 1; ++i) {
            if (a[i] + 1 < a[i + 1]) {
                a[i] += 1;
                a[i + 1] -= 1;
            }
        }

        // Find the tallest stack
        int maxIndex = 0;
        for (int i = 1; i < (int)a.size(); ++i) {
            if (a[i] > a[maxIndex]) {
                maxIndex = i;
            }
        }

        // Remove the tallest stack and add its height to the end of the output array
        int maxHeight = a[maxIndex];
        a.erase(a.begin() + maxIndex);

        // Check if the current state matches the sorted array
        if (!std::equal(a.begin(), a.end(), sortedA.begin())) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& num : a) {
        std::cin >> num;
    }

    if (canBeSortedUsingRavioliSort(a)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}