#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> lengths(4);
    for (int &length : lengths) {
        std::cin >> length;
    }
    std::sort(lengths.begin(), lengths.end());
    if (lengths[0] == lengths[1] && lengths[2] == lengths[3]) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}