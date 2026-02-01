#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;

    int numRemoved = 0;
    int numZeroes = std::count(S.begin(), S.end(), '0');
    int numOnes = S.size() - numZeroes;

    numRemoved = 2 * std::min(numZeroes, numOnes);

    std::cout << numRemoved << std::endl;

    return 0;
}