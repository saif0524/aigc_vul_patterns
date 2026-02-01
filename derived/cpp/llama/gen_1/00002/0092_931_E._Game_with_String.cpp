#include <iostream>
#include <string>
#include <map>
#include <iomanip>

double solve(const std::string& s) {
    int n = s.size();
    std::map<char, int> first;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (first.find(c) == first.end()) {
            first[c] = 1;
        } else {
            first[c]++;
        }
    }

    double p = 0.0;
    for (const auto& kv : first) {
        char c = kv.first;
        int count = kv.second;
        if (n % count == 0) continue;
        double p_c = static_cast<double>(count) / n;
        std::map<std::string, int> second;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int offset = (i + 1) % n;
                char d = s[offset];
                if (second.find(std::string(1, d)) == second.end()) {
                    second[std::string(1, d)] = 1;
                } else {
                    second[std::string(1, d)]++;
                }
            }
        }

        double p_c_second = 0.0;
        for (const auto& kv2 : second) {
            int count2 = kv2.second;
            p_c_second += static_cast<double>(count2) / count;
        }
        p += p_c * (1.0 - p_c_second);
    }

    return p;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << std::fixed << std::setprecision(12) << solve(s) << std::endl;
    return 0;
}