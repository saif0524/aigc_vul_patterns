#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;

    std::cin >> N >> S;

    int consecutive_x = 0;
    int answered_questions = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'x') {
            consecutive_x++;
        } else {
            consecutive_x = 0;
        }

        if (consecutive_x == 2) {
            break;
        }

        answered_questions++;
    }

    std::cout << answered_questions << std::endl;

    return 0;
}