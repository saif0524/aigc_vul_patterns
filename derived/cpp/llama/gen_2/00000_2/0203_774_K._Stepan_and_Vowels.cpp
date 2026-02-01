#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string result = "";
    result += s[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            if ((s[i] == 'e' || s[i] == 'o') && count == 1) {
                result += s[i];
                count++;
            } else if (!(s[i] == 'e' || s[i] == 'o') || count >= 2) {
                count++;
            }
        } else {
            result += s[i];
            count = 1;
        }
    }

    std::cout << result << std::endl;

    return 0;
}