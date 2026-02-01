#include <iostream>
#include <string>

long long find(int index, int nonZero, const std::string& n, int k) {
    if (index == n.size()) {
        return nonZero == k ? 1 : 0;
    }
    long long ans = 0;
    for (int digit = 0; digit <= (index == 0 ? n[index] - '0' : 9); digit++) {
        ans += find(index + 1, nonZero + (digit > 0 ? 1 : 0), n, k);
    }
    return ans;
}

int main() {
    std::string n;
    int k;
    std::cin >> n >> k;
    std::cout << find(0, 0, n, k) - 1 << std::endl;
    return 0;
}