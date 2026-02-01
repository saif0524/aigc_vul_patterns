#include <iostream>
#include <vector>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        int swaps = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    ++swaps;
                }
            }
        }
        std::cout << swaps << std::endl;
    }
    return 0;
}