#include <iostream>
#include <string>

int main() {
    std::string X;
    std::cin >> X;
    int length = X.size();
    int cnt = 0;

    for (int i = 0; i < length - 1; i++) {
        if (X[i] == 'S' && X[i + 1] == 'T') {
            X[i] = '0';
            X[i + 1] = '0';
            cnt += 2;
            i = -1;
        }
    }

    int ans = 0;
    for (char c : X) {
        if (c != '0') ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}