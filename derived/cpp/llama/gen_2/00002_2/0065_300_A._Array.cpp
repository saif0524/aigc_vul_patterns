#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> set1, set2, set3;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            set1.push_back(a[i]);
        } else if (a[i] > 0) {
            set2.push_back(a[i]);
        } else {
            set3.push_back(a[i]);
        }
    }

    if (set1.size() % 2 == 0) {
        int last = set1.back();
        set1.pop_back();
        set2.push_back(last);
    }

    std::cout << set1.size() << " ";
    for (int i = 0; i < set1.size(); i++) {
        std::cout << set1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << set2.size() << " ";
    for (int i = 0; i < set2.size(); i++) {
        std::cout << set2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << set3.size() << " ";
    for (int i = 0; i < set3.size(); i++) {
        std::cout << set3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}