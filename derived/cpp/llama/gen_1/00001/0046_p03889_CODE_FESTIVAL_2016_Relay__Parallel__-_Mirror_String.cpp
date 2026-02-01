#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    std::string reversed_S = S;
    int n = S.size();
    for (int i = 0; i < n / 2; i++) {
        std::swap(reversed_S[i], reversed_S[n - i - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (S[i] == 'b') reversed_S[i] = 'd';
        else if (S[i] == 'd') reversed_S[i] = 'b';
        else if (S[i] == 'p') reversed_S[i] = 'q';
        else if (S[i] == 'q') reversed_S[i] = 'p';
    }

    if (S == reversed_S) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}