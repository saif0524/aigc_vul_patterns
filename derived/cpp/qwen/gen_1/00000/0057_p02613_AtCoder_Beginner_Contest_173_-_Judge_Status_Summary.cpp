#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;
    std::unordered_map<std::string, int> verdicts = {{"AC", 0}, {"WA", 0}, {"TLE", 0}, {"RE", 0}};
    std::string verdict;
    for (int i = 0; i < N; ++i) {
        std::cin >> verdict;
        verdicts[verdict]++;
    }
    std::cout << "AC x " << verdicts["AC"] << std::endl;
    std::cout << "WA x " << verdicts["WA"] << std::endl;
    std::cout << "TLE x " << verdicts["TLE"] << std::endl;
    std::cout << "RE x " << verdicts["RE"] << std::endl;
    return 0;
}