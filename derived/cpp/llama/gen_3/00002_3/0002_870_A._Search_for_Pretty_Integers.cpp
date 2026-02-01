#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::set<int> setA(a.begin(), a.end());
    std::set<int> setB(b.begin(), b.end());

    std::set<int> intersection;
    for (int i = 0; i < n; i++) {
        if (setB.find(a[i])!= setB.end()) {
            intersection.insert(a[i]);
        }
    }

    if (!intersection.empty()) {
        std::cout << *intersection.begin() << std::endl;
    } else {
        int minA = *std::min_element(a.begin(), a.end());
        int minB = *std::min_element(b.begin(), b.end());
        std::cout << std::min(minA, minB) << std::max(minA, minB) << std::endl;
    }

    return 0;
}