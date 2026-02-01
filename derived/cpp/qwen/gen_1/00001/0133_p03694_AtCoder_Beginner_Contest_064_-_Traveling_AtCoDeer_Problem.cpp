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
    int min_distance = a[N-1] - a[0];
    std::cout << min_distance << std::endl;
    return 0;
}