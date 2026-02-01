#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i < n - 1 && s[i + 1] == '1') {
                count += 2;
                i++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}