#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) break;
        std::unordered_map<int, long long> sales;
        for (int i = 0; i < n; ++i) {
            int id, p, q;
            std::cin >> id >> p >> q;
            sales[id] += static_cast<long long>(p) * q;
        }
        std::vector<int> goodWorkers;
        for (const auto& entry : sales) {
            if (entry.second >= 1000000) {
                goodWorkers.push_back(entry.first);
            }
        }
        if (goodWorkers.empty()) {
            std::cout << "NA" << std::endl;
        } else {
            for (int id : goodWorkers) {
                std::cout << id << std::endl;
            }
        }
    }
    return 0;
}