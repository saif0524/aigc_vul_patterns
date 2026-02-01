#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::map<std::string, std::vector<std::string>> cheeseMap;
    std::string name, type;

    for (int i = 0; i < N; i++) {
        std::cin >> name >> type;
        if (cheeseMap.find(type)!= cheeseMap.end()) {
            cheeseMap[type].push_back(name);
        } else {
            cheeseMap[type] = {name};
        }
    }

    int result = 0;
    if (cheeseMap.find("soft")!= cheeseMap.end()) {
        result = cheeseMap["soft"].size();
    }
    std::cout << result << std::endl;

    return 0;
}