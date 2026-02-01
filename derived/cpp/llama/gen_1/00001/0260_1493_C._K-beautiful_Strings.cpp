#include <iostream>
#include <string>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    if (n % k != 0) {
        std::cout << -1 << std::endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        char c = s[i];

        for (int j = static_cast<int>(c + 1); j <= 'z'; j++) {
            std::string temp = s.substr(0, i);
            temp += static_cast<char>(j);

            int times[26] = {0};
            for (int p = 0; p < static_cast<int>(temp.size()); p++) {
                times[temp[p] - 'a']++;
            }

            std::string res;
            res.reserve(n);
            res += temp;

            for (int p = 0; p < 26; p++) {
                int left = (k - (times[p] % k)) % k;
                while (left > 0) {
                    res += static_cast<char>('a' + p);
                    left--;
                }
            }

            if (res.size() < n) {
                for (int p = 0; p < 26; p++) {
                    int left = k - (times[p] % k);
                    if (left == k) {
                        while (res.size() < n) {
                            res += static_cast<char>('a' + p);
                        }
                        break;
                    }
                }
            }

            if (res.size() == n) {
                std::cout << res << std::endl;
                return;
            }
        }

        s[i] = 'a';
    }

    for (int i = 0; i < 26; i++) {
        int left = k;
        while (left > 0) {
            s += static_cast<char>('a' + i);
            left--;
        }
    }

    if (s.size() == n) {
        std::cout << s << std::endl;
        return;
    }

    std::cout << -1 << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int test;
    std::cin >> test;

    while (test-- > 0) {
        solve();
    }

    return 0;
}