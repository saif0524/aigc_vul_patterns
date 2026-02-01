#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int h_count = std::count(s.begin(), s.end(), 'H');
    int min_swaps = n;

    for (int i = 0; i < n; ++i) {
        int swaps = 0;
        for (int j = 0; j < h_count; ++j) {
            if (s[(i + j) % n] == 'T') {
                swaps++;
            }
        }
        min_swaps = std::min(min_swaps, swaps);
    }

    std::cout << min_swaps << std::endl;

    return 0;
}