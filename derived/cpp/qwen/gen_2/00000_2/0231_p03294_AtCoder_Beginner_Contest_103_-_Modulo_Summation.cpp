#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
        result += a[i] - 1;
    }
    std::cout << result;
}