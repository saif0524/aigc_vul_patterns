#include <iostream>
#include <vector>

int bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ++swapCount;
            }
        }
    }
    return swapCount;
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) break;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        int result = bubbleSort(arr);
        std::cout << result << std::endl;
    }
    return 0;
}