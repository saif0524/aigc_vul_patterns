#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> titles(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> titles[i];
    }

    std::set<std::string> substrings;
    for (const auto& title : titles) {
        for (int i = 0; i < title.size(); ++i) {
            for (int j = i + 1; j <= title.size(); ++j) {
                substrings.insert(title.substr(i, j - i));
            }
        }
    }

    for (int length = 1; ; ++length) {
        std::vector<std::string> candidates;
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            if (length == 1 && substrings.find(std::string(1, c1)) == substrings.end()) {
                candidates.push_back(std::string(1, c1));
            } else if (length > 1) {
                for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                    std::string candidate(2, ' ');
                    candidate[0] = c1;
                    candidate[1] = c2;
                    if (substrings.find(candidate) == substrings.end()) {
                        candidates.push_back(candidate);
                    }
                }
            }
        }

        if (!candidates.empty()) {
            std::sort(candidates.begin(), candidates.end());
            std::cout << candidates[0] << '\n';
            break;
        }
    }

    return 0;
}