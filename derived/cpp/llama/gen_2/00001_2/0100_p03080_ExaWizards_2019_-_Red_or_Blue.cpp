#include <iostream>
#include <string>

int main() {
    int N;
    std::string s;

    std::cin >> N >> s;

    int red = 0, blue = 0;
    for (char c : s) {
        if (c == 'R') red++;
        else blue++;
    }

    if (red > blue) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}