#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.size();
    int max_l = 0;
    for (int l = 1; l <= n + k; ++l) {
        if ((n + k) % l == 0) {
            bool valid = true;
            for (int j = 0; j < l; ++j) {
                for (int i = j; i < n + k - l; i += l) {
                    if (i + l < n && (s[i] != s[i + l])) {
                        valid = false;
                        break;
                    }
                    if (i + l >= n && i + l - n < k && (s[i] != s[i + l - n])) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) max_l = l;
        }
    }
    std::cout << max_l << std::endl;
    return 0;
}