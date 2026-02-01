#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < N / 2; i++) {
        int diff = a[N - 1 - i] - a[i];
        if (diff % (N - 1) == 0) {
            std::cout << a[i] << " " << a[N - 1 - i] << std::endl;
            break;
        }
    }

    return 0;
}