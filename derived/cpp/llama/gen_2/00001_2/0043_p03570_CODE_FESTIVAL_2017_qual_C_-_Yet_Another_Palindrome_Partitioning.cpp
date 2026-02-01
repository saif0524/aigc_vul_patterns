#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; ) {
        std::unordered_map<char, int> freq;
        int max_freq = 0;

        for (int j = i; j < n; ++j) {
            freq[s[j]]++;
            max_freq = std::max(max_freq, freq[s[j]]);

            bool ok = true;
            int odd_count = 0;
            for (const auto& p : freq) {
                if (p.second % 2 != 0) {
                    odd_count++;
                }
                if (odd_count > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans++;
                i = j + 1;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}