#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int n = s.length();
    int N = 0;

    while (n > 0) {
        std::unordered_map<char, int> freq;
        for (int i = 0; i < n; ++i) {
            ++freq[s[i]];
        }

        bool ok = false;
        for (int i = 0; i < n; ++i) {
            std::unordered_map<char, int> freq1;
            for (int j = 0; j <= i; ++j) {
                ++freq1[s[j]];
            }

            bool ok1 = true;
            int odd_count = 0;
            for (const auto& pair : freq1) {
                if (pair.second % 2 != 0) {
                    ++odd_count;
                }
                if (odd_count > 1) {
                    ok1 = false;
                    break;
                }
            }

            if (ok1) {
                int idx = i + 1;
                while (idx < n && freq[s[idx]] == 0) {
                    ++idx;
                }

                if (idx == n) {
                    ok = true;
                    n = i + 1;
                    break;
                }

                --freq[s[idx]];
            }
        }

        if (!ok) {
            int idx = n - 1;
            while (freq[s[idx]] == 0) {
                --idx;
            }

            --freq[s[idx]];
            --n;
        }

        ++N;
    }

    std::cout << N << std::endl;

    return 0;
}