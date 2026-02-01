#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isValid = true;
        for (int j = 0; j < n; j++) {
            if (i != j && s[j] == 'I') {
                isValid = false;
                break;
            }
        }
        if (s[i] != 'F' && isValid) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}