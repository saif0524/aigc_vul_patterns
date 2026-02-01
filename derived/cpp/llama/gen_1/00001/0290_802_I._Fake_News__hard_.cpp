#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.size();
        long long sum = 0;
        std::unordered_map<std::string, int> cnt;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                std::string sub = s.substr(i, j - i);
                if (cnt.find(sub) == cnt.end()) {
                    cnt[sub] = 0;
                }
                cnt[sub]++;
            }
        }

        for (auto& it : cnt) {
            sum += (long long)it.second * (it.second + 1) / 2;
        }

        std::cout << sum << std::endl;
    }
    return 0;
}