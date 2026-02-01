#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n-1), c(n-2);
    std::unordered_map<int, int> count;

    for (int &x : a) {
        std::cin >> x;
        count[x]++;
    }
    for (int &x : b) {
        std::cin >> x;
        count[x]--;
    }
    for (int &x : c) {
        std::cin >> x;
        count[x]--;
    }

    int first, second;
    bool foundFirst = false;
    for (const auto &p : count) {
        if (p.second == 1) {
            if (!foundFirst) {
                first = p.first;
                foundFirst = true;
            } else {
                second = p.first;
            }
        }
    }

    std::cout << first << "\n" << second;

    return 0;
}