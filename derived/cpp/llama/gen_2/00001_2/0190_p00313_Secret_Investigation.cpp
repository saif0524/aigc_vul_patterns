#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    int x;
    std::cin >> x;
    std::set<int> a;
    for (int i = 0; i < x; i++) {
        int ai;
        std::cin >> ai;
        a.insert(ai);
    }

    int y;
    std::cin >> y;
    std::set<int> b;
    for (int i = 0; i < y; i++) {
        int bi;
        std::cin >> bi;
        b.insert(bi);
    }

    int z;
    std::cin >> z;
    std::set<int> c;
    for (int i = 0; i < z; i++) {
        int ci;
        std::cin >> ci;
        c.insert(ci);
    }

    std::set<int> notA;
    for (int i = 1; i <= n; i++) {
        if (a.find(i) == a.end()) {
            notA.insert(i);
        }
    }

    std::set<int> notAC;
    for (auto& i : notA) {
        if (c.find(i) != c.end()) {
            notAC.insert(i);
        }
    }

    std::set<int> bC;
    for (auto& i : b) {
        if (c.find(i) != c.end()) {
            bC.insert(i);
        }
    }

    std::set<int> result;
    for (auto& i : notAC) {
        result.insert(i);
    }
    for (auto& i : bC) {
        result.insert(i);
    }

    std::cout << result.size() << std::endl;

    return 0;
}