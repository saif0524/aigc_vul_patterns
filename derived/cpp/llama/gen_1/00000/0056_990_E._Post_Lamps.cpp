#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> blocked(m);
    for (int i = 0; i < m; i++) {
        std::cin >> blocked[i];
    }

    std::vector<int> costs(k);
    for (int i = 0; i < k; i++) {
        std::cin >> costs[i];
    }

    int result = INT_MAX;
    for (int power = 1; power <= k; power++) {
        int cost = costs[power - 1];
        int count = 0;
        int position = 0;

        bool possible = true;
        while (position < n) {
            int nextPosition = position + power;
            while (m > 0 && blocked[m - 1] <= nextPosition) {
                m--;
                nextPosition++;
            }

            if (nextPosition > n) {
                if (position != 0 && m > 0 && blocked[m - 1] == n) {
                    possible = false;
                    break;
                } else {
                    count++;
                    break;
                }
            }

            position = nextPosition;
            count++;
        }

        if (possible) {
            result = std::min(result, count * cost);
        }
    }

    if (result == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << result << std::endl;
    }

    return 0;
}