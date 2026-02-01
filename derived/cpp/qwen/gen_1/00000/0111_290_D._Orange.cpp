#include <iostream>
#include <string>

int main() {
    std::string s;
    int n;
    std::cin >> s >> n;
    for (char &c : s) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = tolower(c);
            c = ((c - 'a' + n) % 26) + 'a';
            if (isUpper) {
                c = toupper(c);
            }
        }
    }
    std::cout << s;
    return 0;
}