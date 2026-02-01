#include <iostream>

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        int under10 = 0, teens = 0, twenties = 0, thirties = 0, forties = 0, fifties = 0, over60 = 0;

        for (int i = 0; i < n; i++) {
            int age;
            std::cin >> age;

            if (age < 10) {
                under10++;
            } else if (age < 20) {
                teens++;
            } else if (age < 30) {
                twenties++;
            } else if (age < 40) {
                thirties++;
            } else if (age < 50) {
                forties++;
            } else if (age < 60) {
                fifties++;
            } else {
                over60++;
            }
        }

        std::cout << under10 << std::endl;
        std::cout << teens << std::endl;
        std::cout << twenties << std::endl;
        std::cout << thirties << std::endl;
        std::cout << forties << std::endl;
        std::cout << fifties << std::endl;
        std::cout << over60 << std::endl;
    }

    return 0;
}