#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string T;
    std::cin >> T;
    int Q;
    std::cin >> Q;
    std::unordered_set<std::string> patterns;

    for (int i = 0; i < T.size(); ++i) {
        for (int j = 1; j <= T.size() - i; ++j) {
            patterns.insert(T.substr(i, j));
        }
    }

    while (Q--) {
        std::string P;
        std::cin >> P;
        std::cout << (patterns.count(P) ? 1 : 0) << std::endl;
    }

    return 0;
}