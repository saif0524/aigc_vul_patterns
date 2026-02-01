#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    int ac = 0, wa = 0, tle = 0, re = 0;

    for (int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;

        if (S == "AC") ac++;
        else if (S == "WA") wa++;
        else if (S == "TLE") tle++;
        else if (S == "RE") re++;
    }

    std::cout << "AC x " << ac << std::endl;
    std::cout << "WA x " << wa << std::endl;
    std::cout << "TLE x " << tle << std::endl;
    std::cout << "RE x " << re << std::endl;

    return 0;
}