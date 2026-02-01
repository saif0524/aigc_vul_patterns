#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;
    int x;
    while (std::cin >> x) {
        v.push_back(x);
    }

    std::sort(v.begin(), v.end());

    int result = 0;
    if (v.size() > 0 && v[0] != 0) {
        result = 1;
    }

    std::cout << result << std::endl;

    return 0;
}