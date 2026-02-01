#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n) {
            std::string t = "";
            for (int j = l; j <= r; j++) {
                if (t.empty() || t.back()!= s[j]) {
                    t += s[j];
                }
            }
            bool isPalin = true;
            for (int j = 0; j < t.length() / 2; j++) {
                if (t[j]!= t[t.length() - j - 1]) {
                    isPalin = false;
                    break;
                }
            }
            if (isPalin) {
                if ((r - l + 1) % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            l--, r++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int l = i, r = i + 1;
        while (l >= 0 && r < n) {
            std::string t = "";
            for (int j = l; j <= r; j++) {
                if (t.empty() || t.back()!= s[j]) {
                    t += s[j];
                }
            }
            bool isPalin = true;
            for (int j = 0; j < t.length() / 2; j++) {
                if (t[j]!= t[t.length() - j - 1]) {
                    isPalin = false;
                    break;
                }
            }
            if (isPalin) {
                if ((r - l + 1) % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            l--, r++;
        }
    }

    std::cout << even << " " << odd << std::endl;

    return 0;
}