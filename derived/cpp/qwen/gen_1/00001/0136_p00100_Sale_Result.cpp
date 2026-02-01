#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::unordered_map<int, long long> sales;
        for (int i = 0; i < n; ++i) {
            int id, p, q;
            std::cin >> id >> p >> q;
            sales[id] += static_cast<long long>(p) * q;
        }
        bool found = false;
        for (const auto& [id, total] : sales) {
            if (total >= 1000000) {
                if (found) std::cout << "\n";
                std::cout << id;
                found = true;
            }
        }
        if (!found) std::cout << "NA";
        std::cout << "\n";
    }
    return 0;
}