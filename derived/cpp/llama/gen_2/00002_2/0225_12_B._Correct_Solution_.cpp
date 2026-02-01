#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string n, m;
    std::cin >> n >> m;

    std::string sorted_n = n;
    std::sort(sorted_n.begin(), sorted_n.end());

    if (sorted_n[0] == '0') {
        for (int i = 1; i < sorted_n.size(); ++i) {
            if (sorted_n[i] != '0') {
                std::swap(sorted_n[0], sorted_n[i]);
                break;
            }
        }
    }

    if (m == sorted_n) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "WRONG_ANSWER" << std::endl;
    }

    return 0;
}