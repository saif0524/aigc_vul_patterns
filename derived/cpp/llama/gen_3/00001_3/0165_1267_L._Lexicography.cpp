#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, l, k;
    std::cin >> n >> l >> k;

    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());

    std::vector<std::string> words(n);
    int len = (n * l - k) / n;
    int ind = 0, left = 0, right = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ind < s.size()) {
                if (j < k) {
                    words[j].push_back(s[ind]);
                    ind++;
                } else {
                    if (left <= right && ind < s.size()) {
                        words[j].push_back(s[ind]);
                        ind++;
                        left = right + 1;
                        right = k - 1 + len;
                    }
                }
            }
        }
    }

    for (const auto& word : words) {
        std::cout << word << "\n";
    }

    return 0;
}