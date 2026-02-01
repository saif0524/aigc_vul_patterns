#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int open = 0, close = 0;
    std::vector<std::vector<int>> ans;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open++;
            if (close > 0) {
                close--;
                cnt++;
                ans.push_back({i + 1});
            }
        } else {
            if (open > 0) {
                open--;
                cnt++;
                ans.back().push_back(i + 1);
            } else {
                close++;
            }
        }
    }

    std::cout << cnt << std::endl;
    for (auto& v : ans) {
        std::cout << v.size() << std::endl;
        for (int x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}