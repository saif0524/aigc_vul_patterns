#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'o') {
            ++count;
        } else {
            if (i < N - 1 && S[i + 1] == 'x') {
                break;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}