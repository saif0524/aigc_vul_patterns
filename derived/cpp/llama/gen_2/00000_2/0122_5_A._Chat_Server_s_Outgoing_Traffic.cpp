#include <iostream>
#include <string>
#include <vector>

int main() {
    int online = 0;
    long long ans = 0;
    std::string s;

    while (std::getline(std::cin, s)) {
        if (s[0] == '+') {
            online++;
        } else if (s[0] == '-') {
            online--;
        } else {
            size_t pos = s.find(':');
            std::string message = s.substr(pos + 1);
            ans += online * message.length();
        }
    }

    std::cout << ans << std::endl;
    return 0;
}