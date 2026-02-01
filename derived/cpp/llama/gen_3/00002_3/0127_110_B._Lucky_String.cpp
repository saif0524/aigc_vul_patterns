#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string ans;
    char c = 'a';
    for (int i = 0; i < n; i++) {
        ans += c;
        c = (c == 'd')? 'a' : c + 1;
    }
    std::cout << ans << std::endl;
    return 0;
}