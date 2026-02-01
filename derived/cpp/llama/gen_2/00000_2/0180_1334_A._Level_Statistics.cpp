#include <iostream>

int main() {
    int testCases;
    std::cin >> testCases;

    while (testCases--) {
        int n;
        std::cin >> n;

        int prevPlays = 0;
        int prevClears = 0;
        bool isValid = true;

        for (int i = 0; i < n; ++i) {
            int plays, clears;
            std::cin >> plays >> clears;

            if (plays < prevPlays || clears < prevClears || (plays > prevPlays && clears > prevClears && plays - prevPlays != clears - prevClears)) {
                isValid = false;
                break;
            }

            prevPlays = plays;
            prevClears = clears;
        }

        std::cout << (isValid ? "YES" : "NO") << std::endl;
    }

    return 0;
}