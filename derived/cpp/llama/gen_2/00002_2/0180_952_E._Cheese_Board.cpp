#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> cheeseTypes;

    for (int i = 0; i < n; i++) {
        std::string name, type;
        std::cin >> name >> type;

        if (cheeseTypes.find(type)!= cheeseTypes.end()) {
            cheeseTypes[type]++;
        } else {
            cheeseTypes[type] = 1;
        }
    }

    int maxCount = 0;
    for (auto& pair : cheeseTypes) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }

    std::cout << maxCount << std::endl;

    return 0;
}