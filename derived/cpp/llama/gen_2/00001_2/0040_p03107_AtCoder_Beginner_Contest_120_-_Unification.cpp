#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int count = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        if (S[i] == '0') {
            if (i < n - 1 && S[i + 1] == '1') {
                count += 2;
                i++;
            }
        } else {
            if (i > 0 && S[i - 1] == '0') {
                count += 2;
                i++;
            }
        }
    }

    if (count > n) {
        count = n;
    }

    std::cout << count << std::endl;

    return 0;
}