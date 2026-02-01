#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> suits = {"S", "H", "C", "D"};
    std::unordered_map<std::string, std::vector<bool>> cardMap;

    for (const auto& suit : suits) {
        cardMap[suit] = std::vector<bool>(14, false);
    }

    for (int i = 0; i < n; ++i) {
        std::string suit;
        int rank;
        std::cin >> suit >> rank;
        cardMap[suit][rank] = true;
    }

    for (const auto& suit : suits) {
        for (int rank = 1; rank <= 13; ++rank) {
            if (!cardMap[suit][rank]) {
                std::cout << suit << " " << rank << std::endl;
            }
        }
    }

    return 0;
}