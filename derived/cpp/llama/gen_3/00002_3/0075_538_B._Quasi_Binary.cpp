#include <iostream>
#include <vector>

std::vector<int> findQuasibinaryRepresentation(int n) {
    std::vector<int> representation;
    int maxDigit = 0;
    int temp = n;

    while (temp > 0) {
        maxDigit = std::max(maxDigit, temp % 10);
        temp /= 10;
    }

    for (int i = 0; i < maxDigit; i++) {
        intnum_t temp = n;
        std::vector<int> currentRepresentation;

        while (temp > 0) {
            if (temp % 10 > i) {
                currentRepresentation.push_back(1);
                temp -= 1;
            } else {
                currentRepresentation.push_back(0);
            }
            temp /= 10;
        }

        int num = 0;
        int power = 1;
        for (int j = currentRepresentation.size() - 1; j >= 0; j--) {
            if (currentRepresentation[j] == 1) {
                num += power;
            }
            power *= 10;
        }
        representation.push_back(num);
    }

    return representation;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> representation = findQuasibinaryRepresentation(n);

    std::cout << representation.size() << std::endl;
    for (int num : representation) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}