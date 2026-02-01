#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int hCount = std::count(s.begin(), s.end(), 'H');
    int tCount = n - hCount;

    int minSwaps = n;

    for (int i = 0; i < n; ++i) {
        int swaps = 0;
        for (int j = 0; j < hCount; ++j) {
            if (s[(i + j) % n] == 'T') {
                swaps++;
            }
        }
        minSwaps = std::min(minSwaps, swaps);
    }

    std::cout << minSwaps << std::endl;

    return 0;
}