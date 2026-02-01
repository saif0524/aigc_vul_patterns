#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int k = 0;
    std::vector<int> ans;

    std::string str = std::to_string(n);
    for (char c : str) {
        k = std::max(k, c - '0');
    }

    for (int i = 0; i < k; i++) {
        std::string s;
        for (char c : str) {
            if (c - '0' > i) {
                s += '1';
            } else {
                s += '0';
            }
        }
        ans.push_back(std::stoi(s));
    }

    std::cout << k << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << ans[i];
        if (i!= k - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}