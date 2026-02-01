#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<std::string> softCheeses;
    std::string name, type;
    int hardCount = 0;

    for (int i = 0; i < N; ++i) {
        std::cin >> name >> type;
        if (type == "soft") {
            softCheeses.insert(name);
        } else {
            ++hardCount;
        }
    }

    std::cout << hardCount;
    return 0;
}