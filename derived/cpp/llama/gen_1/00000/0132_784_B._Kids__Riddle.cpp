#include <iostream>
#include <bitset>

int main() {
    int n;
    std::cin >> n;

    int cnt = 0;
    std::bitset<32> b(n);
    std::string s = b.to_string();

    for (char c : s) {
        if (c == '1') {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}