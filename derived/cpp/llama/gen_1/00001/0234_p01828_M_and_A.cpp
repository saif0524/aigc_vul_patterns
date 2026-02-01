#include <iostream>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    int j = 0;
    for (int i = 0; i < t.size(); ++i) {
        if (j < s.size() && s[j] == t[i]) {
            ++j;
        }
    }
    return j == s.size();
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << (isSubsequence(s, t) ? "Yes" : "No") << std::endl;
    return 0;
}