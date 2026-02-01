#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string level;
    std::cin >> level;

    std::vector<int> platforms;
    for (int i = 0; i < n; ++i) {
        if (level[i] == '*') {
            platforms.push_back(i);
        }
    }

    int size = platforms.size();
    for (int i = 0; i < size - 4; ++i) {
        for (int j = i + 1; j < size - 3; ++j) {
            int diff = platforms[j] - platforms[i];
            int next = platforms[j] + diff;
            if (next < size && platforms[next] == next) {
                next += diff;
                if (next < size && platforms[next] == next) {
                    next += diff;
                    if (next < size && platforms[next] == next) {
                        std::cout << "yes";
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "no";
    return 0;
}