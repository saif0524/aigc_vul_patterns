#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    bool found = false;

    for (int i = 1; i < n; ++i) {
        if (s[i] < s[i - 1]) {
            std::cout << "YES" << std::endl;
            std::cout << i << " " << i + 1 << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        for (int i = 1; i < n; ++i) {
            std::string temp = s;
            int l = i, r = i;
            while (l > 0 && temp[l] == temp[l - 1]) --l;
            while (r < n - 1 && temp[r] == temp[r + 1]) ++r;
            std::reverse(temp.begin() + l, temp.begin() + r + 1);
            if (temp < s) {
                std::cout << "YES" << std::endl;
                std::cout << l + 1 << " " << r + 1 << std::endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "NO" << std::endl;
    }

    return 0;
}