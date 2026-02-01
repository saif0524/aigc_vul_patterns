#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<int> count(7, 0);
    std::vector<int> ages;

    while (true) {
        std::cin >> n;
        if (n == 0) break;
        ages.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> ages[i];
        }
        std::fill(count.begin(), count.end(), 0);
        for (int age : ages) {
            if (age < 10) count[0]++;
            else if (age < 20) count[1]++;
            else if (age < 30) count[2]++;
            else if (age < 40) count[3]++;
            else if (age < 50) count[4]++;
            else if (age < 60) count[5]++;
            else count[6]++;
        }
        for (int c : count) {
            std::cout << c << '\n';
        }
    }
    return 0;
}