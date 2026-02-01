#include <iostream>
#include <string>

int main() {
    int N, AC = 0, WA = 0, TLE = 0, RE = 0;
    std::string S;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> S;
        if (S == "AC") AC++;
        else if (S == "WA") WA++;
        else if (S == "TLE") TLE++;
        else if (S == "RE") RE++;
    }

    std::cout << "AC x " << AC << std::endl;
    std::cout << "WA x " << WA << std::endl;
    std::cout << "TLE x " << TLE << std::endl;
    std::cout << "RE x " << RE << std::endl;

    return 0;
}