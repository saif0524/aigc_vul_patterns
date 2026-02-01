#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string s, p, t;
    std::cin >> s >> p >> t;

    int left = 0, right = s.length() - 1;
    while (left < n && s[left] != t[0]) {
        left++;
    }

    while (right >= 0 && s[right] != t[0]) {
        right--;
    }

    std::cout << left + 1 << " " << right + 1 << std::endl;

    return 0;
}