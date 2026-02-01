#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> volumes(n);

    for (int i = 0; i < n; i++) {
        std::cin >> volumes[i];
    }

    double avg = 0.0;
    for (int volume : volumes) {
        avg += volume;
    }
    avg /= n;

    if (std::floor(avg) != avg) {
        std::cout << "Unrecoverable configuration.";
        return 0;
    }

    int occurrences = 0;
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < n; i++) {
        if (volumes[i] != avg) {
            if (idx1 == -1) idx1 = i + 1;
            else if (idx2 == -1) idx2 = i + 1;
            else {
                std::cout << "Unrecoverable configuration.";
                return 0;
            }
        }
    }

    if (idx1 == -1) {
        std::cout << "Exemplary pages.";
    } else {
        int diff = std::abs(volumes[idx1 - 1] - avg);
        std::cout << diff << " ml. from cup #" << (volumes[idx1 - 1] < avg ? idx1 : idx2) << " to cup #" << (volumes[idx1 - 1] < avg ? idx2 : idx1);
    }

    return 0;
}