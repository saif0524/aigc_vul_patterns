#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> neg, pos, zero;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            neg.push_back(a[i]);
        } else if (a[i] > 0) {
            pos.push_back(a[i]);
        } else {
            zero.push_back(a[i]);
        }
    }

    if (neg.size() % 2 == 0) {
        pos.push_back(neg.back());
        neg.pop_back();
    }

    std::cout << neg.size() << " ";
    for (int i = 0; i < neg.size(); ++i) {
        std::cout << neg[i] << " ";
    }
    std::cout << std::endl;

    std::cout << pos.size() << " ";
    for (int i = 0; i < pos.size(); ++i) {
        std::cout << pos[i] << " ";
    }
    std::cout << std::endl;

    std::cout << zero.size() << " ";
    for (int i = 0; i < zero.size(); ++i) {
        std::cout << zero[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}