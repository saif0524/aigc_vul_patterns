#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < N - 1; ++i) {
        if ((a[i + 1] - a[i]) % (N - 1) == 0) {
            std::cout << a[i] << " " << a[i + 1] << std::endl;
            return 0;
        }
    }
    return 0;
}