#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }

    int sereja = 0, dima = 0;
    bool serejaTurn = true;

    int left = 0, right = n - 1;
    while (left <= right) {
        if (cards[left] > cards[right]) {
            if (serejaTurn) {
                sereja += cards[left];
            } else {
                dima += cards[left];
            }
            left++;
        } else {
            if (serejaTurn) {
                sereja += cards[right];
            } else {
                dima += cards[right];
            }
            right--;
        }
        serejaTurn = !serejaTurn;
    }

    std::cout << sereja << " " << dima << std::endl;

    return 0;
}