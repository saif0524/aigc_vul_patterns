#include <iostream>
#include <string>

bool check(const std::string& s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            return false;
        }
    }
    for (int i = 0; i < s.size() - 2; ++i) {
        if (s[i] == s[i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, p;
    std::cin >> n >> p;
    std::string s;
    std::cin >> s;
    int index = n - 1;
    while (index >= 0) {
        char c = s[index];
        c++;
        while (c - 'a' < p) {
            s[index] = c;
            if ((index == n - 1 || check(s.substr(0, index + 1))) && 
                (index == n - 1 || (index + 1 == n - 1 || check(s.substr(0, index + 2))))) {
                if (index < n - 1) {
                    for (int i = index + 1; i < n; ++i) {
                        s[i] = 'a';
                    }
                    while (index >= 0) {
                        if (!check(s)) {
                            char c = s[index];
                            c++;
                            while (c - 'a' < p) {
                                s[index] = c;
                                if ((index == n - 1 || check(s.substr(0, index + 1))) && 
                                    (index == n - 1 || (index + 1 == n - 1 || check(s.substr(0, index + 2))))) {
                                    break;
                                } else {
                                    c++;
                                }
                            }
                            if (c - 'a' >= p) {
                                index--;
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
                std::cout << s << std::endl;
                return 0;
            } else {
                c++;
            }
        }
        index--;
    }
    std::cout << "NO" << std::endl;
    return 0;
}