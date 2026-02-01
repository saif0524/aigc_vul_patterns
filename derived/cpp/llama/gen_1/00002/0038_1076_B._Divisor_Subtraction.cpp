#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    int ans = 0;
    while(n != 0) {
        if(n % 2 == 0) {
            n -= 2;
            ans++;
        } else {
            ans++;
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}