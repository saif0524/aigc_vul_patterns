#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string n, m;
    std::cin >> n >> m;

    std::string sorted_n = n;
    std::sort(sorted_n.begin(), sorted_n.end());

    // Remove leading zeros
    int i = 0;
    while (i < sorted_n.size() - 1 && sorted_n[i] == '0') {
        i++;
    }
    sorted_n = sorted_n.substr(i);

    if (sorted_n == m) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "WRONG_ANSWER" << std::endl;
    }

    return 0;
}