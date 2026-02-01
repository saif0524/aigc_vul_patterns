#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> neg, pos, zero;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] < 0) {
            neg.push_back(a[i]);
        } else if (a[i] > 0) {
            pos.push_back(a[i]);
        } else {
            zero.push_back(a[i]);
        }
    }

    int negCount = neg.size();
    int posCount = pos.size();
    int zeroCount = zero.size();

    if (negCount % 2 == 0 && negCount > 1) {
        neg.pop_back();
        pos.push_back(neg.back());
    }

    std::cout << negCount << " ";
    for (int i = 0; i < negCount; i++) {
        std::cout << neg[i] << " ";
    }
    std::cout << std::endl;

    std::cout << posCount << " ";
    for (int i = 0; i < posCount; i++) {
        std::cout << pos[i] << " ";
    }
    std::cout << std::endl;

    std::cout << zeroCount << " ";
    for (int i = 0; i < zeroCount; i++) {
        std::cout << zero[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}