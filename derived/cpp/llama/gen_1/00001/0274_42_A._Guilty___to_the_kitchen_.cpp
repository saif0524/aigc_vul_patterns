#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

std::vector<int> ReadIntegers() {
    std::vector<int> integers;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        integers.push_back(num);
    }
    return integers;
}

int main() {
    int n, v;
    std::cin >> n >> v;
    std::cin.ignore();

    std::vector<int> a = ReadIntegers();
    std::vector<int> b = ReadIntegers();

    double max_x = std::numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            max_x = std::min(max_x, static_cast<double>(b[i]) / a[i]);
        }
    }

    max_x = std::min(max_x, static_cast<double>(v));

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * max_x;
    }

    std::cout.precision(20);
    std::cout << std::min(sum, static_cast<double>(v)) << std::endl;

    return 0;
}