#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long& i : a) {
        std::cin >> i;
    }

    std::vector<long long> stand(n);
    stand[0] = a[0];
    for (int i = 1; i < n; i++) {
        stand[i] = std::max(stand[i-1], a[i]);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += stand[i] - a[i];
    }

    std::cout << sum << std::endl;

    return 0;
}