#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int res = 0;
    for (int i = 0; i < k; i++) {
        res += arr[n - k + i];
    }

    std::cout << res << std::endl;

    return 0;
}