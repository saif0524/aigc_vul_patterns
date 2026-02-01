#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int sum = std::accumulate(v.begin(), v.end(), 0);
    int avg = sum / n;

    if (sum % n!= 0) {
        std::cout << "Unrecoverable configuration." << std::endl;
        return 0;
    }

    int count = 0;
    int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i]!= avg) {
            count++;
            if (v[i] < avg) {
                minIndex = i + 1;
            } else {
                maxIndex = i + 1;
            }
        }
    }

    if (count == 0) {
        std::cout << "Exemplary pages." << std::endl;
    } else if (count == 2) {
        int diff = avg - v[minIndex - 1];
        if (v[maxIndex - 1] - diff == avg) {
            std::cout << diff << " ml. from cup #" << minIndex << " to cup #" << maxIndex << "." << std::endl;
        } else {
            std::cout << "Unrecoverable configuration." << std::endl;
        }
    } else {
        std::cout << "Unrecoverable configuration." << std::endl;
    }

    return 0;
}