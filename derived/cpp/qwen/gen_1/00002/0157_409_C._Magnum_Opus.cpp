#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    std::vector<int> a;
    int tmp;
    while (std::cin >> tmp) {
        a.push_back(tmp);
    }
    std::unordered_set<int> unique_elements(a.begin(), a.end());
    std::cout << std::min((int)unique_elements.size(), 5) << std::endl;
    return 0;
}