#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == '#' && S[i + 1] == '.') {
            ans++;
        }
    }

    int count = 0;
    for (char c : S) {
        if (c == '.') {
            count++;
        }
    }

    std::cout << std::min(ans, count) << std::endl;

    return 0;
}