#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minOperations(int n, int x, int y, std::string num) {
    int count = 0;
    for (int i = n - 1; i >= n - x; i--) {
        if (i == n - y - 1) {
            if (num[i] == '0') {
                count++;
            }
        } else {
            if (num[i] == '1') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::string num;
    std::cin >> num;
    std::cout << minOperations(n, x, y, num) << std::endl;
    return 0;
}