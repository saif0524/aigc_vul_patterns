#include <iostream>
#include <vector>
#include <string>

int main() {
    int N;
    std::cin >> N;
    int soft_count = 0;
    for (int i = 0; i < N; ++i) {
        std::string name, type;
        std::cin >> name >> type;
        if (type == "soft") {
            ++soft_count;
        }
    }
    std::cout << soft_count;
    return 0;
}