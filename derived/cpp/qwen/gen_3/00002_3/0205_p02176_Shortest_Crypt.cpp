#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<int> directions(4, 0);

    for (char c : S) {
        if ('A' <= c && c <= 'M') directions[0]++;
        else if ('N' <= c && c <= 'Z') directions[0]--;
        else if ('a' <= c && c <= 'm') directions[1]++;
        else if ('n' <= c && c <= 'z') directions[1]--;
    }

    std::string result;
    for (int i = 0; i < directions[0]; ++i) result += 'A';
    for (int i = 0; i < -directions[0]; ++i) result += 'N';
    for (int i = 0; i < directions[1]; ++i) result += 'a';
    for (int i = 0; i < -directions[1]; ++i) result += 'n';

    std::cout << result.size() << "\n" << result << "\n";
    return 0;
}