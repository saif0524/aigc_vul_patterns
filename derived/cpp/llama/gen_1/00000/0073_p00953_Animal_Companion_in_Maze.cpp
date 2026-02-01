#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.rbegin(), arr.rend());
    std::cout << arr[k - 1];

    return 0;
}