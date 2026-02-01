#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int n, m, y0, y1;
    std::cin >> n >> m >> y0 >> y1;

    std::vector<int> mice(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mice[i];
    }

    std::vector<int> cheese(m);
    for (int i = 0; i < m; i++) {
        std::cin >> cheese[i];
    }

    std::vector<int> closest(n);
    for (int i = 0; i < n; i++) {
        int minDist = std::numeric_limits<int>::max();
        int closestIndex = -1;
        for (int j = 0; j < m; j++) {
            int dist = std::abs(mice[i] - cheese[j]);
            if (dist < minDist) {
                minDist = dist;
                closestIndex = j;
            }
        }
        closest[i] = closestIndex;
    }

    std::vector<int> counts(m, 0);
    for (int i = 0; i < n; i++) {
        counts[closest[i]]++;
    }

    std::vector<bool> eaten(m, false);
    int hungry = n;
    for (int i = 0; i < n; i++) {
        int index = closest[i];
        if (!eaten[index]) {
            eaten[index] = true;
            hungry -= std::min(counts[index], 1);
            counts[index]--;
        }
    }

    std::cout << hungry << std::endl;

    return 0;
}