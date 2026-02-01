#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<int> a;
    while (std::cin >> n) {
        a.push_back(n);
    }
    std::sort(a.begin(), a.end());
    std::cout << a[0] << std::endl;
    return 0;
}