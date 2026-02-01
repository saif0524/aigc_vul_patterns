#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int first;
    int second;
    bool operator<(const Pair& other) const {
        return (first + other.second) % n < (second + other.first) % n;
    }
};

const int n = 200005;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<Pair> pairs;
    for (int i = 0; i < n; i++) {
        pairs.push_back({a[i], b[i]});
    }

    std::sort(pairs.begin(), pairs.end());

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = (pairs[i].first + pairs[i].second) % n;
    }

    for (int i = 0; i < n; i++) {
        std::cout << c[i] << " ";
    }

    return 0;
}