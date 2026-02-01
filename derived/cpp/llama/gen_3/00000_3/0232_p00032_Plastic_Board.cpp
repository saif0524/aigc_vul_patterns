#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

int main() {
    std::vector<int> rectangles;
    std::vector<int> rhombuses;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        std::istringstream iss(line);
        int a, b, c;
        char comma;
        iss >> a >> comma >> b >> comma >> c;

        int d = std::sqrt(std::pow(a, 2) + std::pow(b, 2) - 2*a*b(std::cos(M_PI/2)));
        if (std::pow(c, 2) == std::pow(a, 2) + std::pow(b, 2)) {
            rectangles.push_back(1);
        } else {
            rectangles.push_back(0);
        }

        if (a == b && std::pow(c, 2) == 2*(std::pow(a, 2))) {
            rhombuses.push_back(1);
        } else {
            rhombuses.push_back(0);
        }
    }

    int rectangleCount = 0;
    for (int i = 0; i < rectangles.size(); i++) {
        rectangleCount += rectangles[i];
    }

    int rhombusCount = 0;
    for (int i = 0; i < rhombuses.size(); i++) {
        rhombusCount += rhombuses[i];
    }

    std::cout << rectangleCount << std::endl;
    std::cout << rhombusCount << std::endl;

    return 0;
}