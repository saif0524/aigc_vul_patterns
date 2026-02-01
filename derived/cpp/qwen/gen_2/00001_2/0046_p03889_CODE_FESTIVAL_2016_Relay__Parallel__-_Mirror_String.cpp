#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;
    std::string T = S;
    std::reverse(T.begin(), T.end());
    for (auto &c : T) {
        if (c == 'b') c = 'd';
        else if (c == 'd') c = 'b';
        else if (c == 'p') c = 'q';
        else if (c == 'q') c = 'p';
    }
    if (S == T) std::cout << "Yes";
    else std::cout << "No";
    return 0;
}