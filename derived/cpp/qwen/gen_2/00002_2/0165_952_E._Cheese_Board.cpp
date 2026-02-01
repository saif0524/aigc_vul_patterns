#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, std::string> cheeses;
    for (int i = 0; i < n; ++i) {
        std::string name, type;
        std::cin >> name >> type;
        cheeses[name] = type;
    }

    int soft_count = 0;
    int hard_count = 0;
    for (auto const& [key, val] : cheeses) {
        if (val == "soft") {
            soft_count++;
        } else {
            hard_count++;
        }
    }

    std::cout << std::min(soft_count, hard_count) << std::endl;

    return 0;
}