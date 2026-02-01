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
    std::sort(a.begin(), a.end());
    std::cout << a[0] << " " << a[N-1] << std::endl;
    return 0;
}