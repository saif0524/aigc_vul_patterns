#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string rebus;
    std::getline(std::cin, rebus);

    std::istringstream iss(rebus);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    int n = std::stoi(tokens.back());
    tokens.pop_back();
    tokens.pop_back(); // remove '='

    int plusCount = 1;
    int minusCount = 0;

    for (const auto& t : tokens) {
        if (t == "+") {
            plusCount++;
        } else if (t == "-") {
            minusCount++;
        }
    }

    int total = plusCount * n - minusCount;
    if (total < n) {
        std::cout << "Impossible\n";
        return 0;
    }

    int plusSum = n;
    int minusSum = total - n;

    std::cout << "Possible\n";
    std::string result;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "?") {
            if (i % 2 == 0) {
                int val = std::min(n, plusSum);
                plusSum -= val;
                result += std::to_string(val) + " ";
            } else {
                int val = std::min(n, minusSum);
                minusSum -= val;
                result += std::to_string(val) + " ";
            }
        } else {
            result += tokens[i] + " ";
        }
    }

    result += "= " + std::to_string(n);
    std::cout << result << "\n";

    return 0;
}