#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> points(n);
    for (int &point : points) {
        std::cin >> point;
    }

    int amazing = 0;
    int best = std::numeric_limits<int>::min();
    int worst = std::numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        if (points[i] > best) {
            best = points[i];
            if (i != 0) {
                amazing++;
            }
        }
        if (points[i] < worst) {
            worst = points[i];
            if (i != 0) {
                amazing++;
            }
        }
    }

    std::cout << amazing << std::endl;
    return 0;
}