#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<long long> S;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "add") {
            long long x;
            std::cin >> x;
            S.insert(x);
        } else if (operation == "del") {
            long long x;
            std::cin >> x;
            S.erase(x);
        } else if (operation == "sum") {
            long long sum = 0;
            int k = 0;

            for (auto it = S.begin(); it != S.end(); ++it) {
                ++k;
                if (k % 5 == 3 || (k % 5 == 0 && k != 0 && ((k / 5) % 2 == 1))) {
                    sum += *it;
                }
            }

            std::cout << sum << std::endl;
        }
    }

    return 0;
}