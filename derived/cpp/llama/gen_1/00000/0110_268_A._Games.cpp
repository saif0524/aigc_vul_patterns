#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> teams[i].first >> teams[i].second;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && teams[i].first == teams[j].first) {
                ++count;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}