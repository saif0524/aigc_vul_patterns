#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character left in the input buffer
    std::string s;
    std::getline(std::cin, s);

    std::string result;
    result += s[0];
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1] && (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'y' || (s[i] == 'e' && count != 2) || (s[i] == 'o' && count != 2))) {
            ++count;
        } else {
            if ((s[i - 1] == 'e' || s[i - 1] == 'o') && count == 2) {
                result += s[i - 1];
            }
            result += s[i];
            count = 1;
        }
    }

    if ((s[n - 1] == 'e' || s[n - 1] == 'o') && count == 2) {
        result += s[n - 1];
    }

    std::cout << result << std::endl;

    return 0;
}